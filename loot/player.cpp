#include "player.h"
#include "constants.h"
#include "world.h"
#include "button.h"
#include "system.h"
#include "direction.h"

Player::Player(System & ab, World & world)
{
  this->ab = &ab;
  this->world = &world;
}

void Player::init(void)
{
  moved = true;
  x = 1;
  y = 1;
  hp = 10;
  sp = 10;
}

Direction Player::getDirection(void) const
{
  return dir;
}

void Player::changeDirection(const Direction direction)
{
  Direction lastDir = this->dir;
  this->dir = direction;
  this->moved = (this->dir != lastDir);
}

bool Player::hasMoved(void) const
{
 return moved;
}

void Player::resetMoved(void)
{
  moved = false;
}

void Player::move(const int8_t distance, const Direction dir)
{
  int8_t nx, ny;  //calculate direction
  switch(dir)
  {
    case Direction::East: nx = 1; break;
    case Direction::South: ny = 1; break;
    case Direction::West: nx = -1; break;
    case Direction::North: ny = -1; break;
  }
  /*
  Serial.print(F("Move : "));
  Serial.print(nx);
  Serial.println(ny);
  */
  this->jump(x + (nx * distance), y + (ny * distance));
  this->battleSteps += abs(distance);
}

void Player::jump(const int8_t x, const int8_t y)
{
  if (world->get(x, y) == 0)
  {
    this->x = x;
    this->y = y;
    moved = true;
  }
}

void Player::step()
{
  Direction lastDir = dir;

  if(ab->isPushed(Button::Left))
  {
    dir = rotateLeft(dir);
    battleSteps++;
  }

  if(ab->isPushed(Button::Right))
    dir = rotateRight(dir);

  if(dir != lastDir)
  {
    moved = true;
    battleSteps++;
  }

  /*
  if(ab->isPushed(Button::Up)) //move 1 step in the looking direction
    move(1,dir);

  if(ab->isPushed(Button::Down))
    move(-1,dir);
  */
  if (ab->isPushed(Button::Up) or (ab->isPushed(Button::Down)))
  {
    //calculate next space
    int8_t nx=0,ny=0;   //using int8 rather than uint8 so negative numbers are possible
    if (dir==Direction::East)
      { nx = 1; }
    if (dir==Direction::South)
      { ny = 1; }
    if (dir==Direction::West)
      { nx = -1; }
    if (dir==Direction::North)
      { ny = -1; }
 
    if (ab->isPushed(Button::Down))  //if they pressed down, flip the direction
    {
      nx = 0-nx;
      ny = 0-ny;
    }
 
    nx += x;  //calculate new coordinate
    ny += y;

    jump(nx,ny);
    moved = true;
  }

  if(moved)
  {
    Serial.print(F("Steps : "));
    Serial.println(battleSteps);    
    if ((battleSteps > 2) && (random(battleSteps) > 10))
    {
      battleSteps = 0;
      Serial.println(F("Battle!"));
      ab->setState(stateBattle);
    }
    
  }

  if(world->getItem(x,y))
  {
    Serial.println(F("Item!"));
    //ab->fillScreen(0);
    //world->setItem(world->getItemID(x,y),x,y,0);
  }
}
