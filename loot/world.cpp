#include "world.h"
#include <stdint.h>

///chests
void Chest::setType(uint8_t type)
{
  this->type = type;
} 

uint8_t Chest::getType()
{
  return type;
}

int8_t Chest::getX()
{
  return x;
}

int8_t Chest::getY()
{
  return y;
}

void Chest::set(const int8_t x,const int8_t y,const uint8_t type)
{
  this->x = x;
  this->y = y;
  this->type = type;
}


//world
void World::init(void)
{
  width = 8;
  height = 8;

  //replace this bit with a progmem loader doodah
  uint8_t leveldata[64] =
  {
    1,1,1,1,1,1,1,1,
    0,0,0,0,0,1,0,0,
    1,1,0,1,1,0,0,1,
    1,0,0,0,0,0,1,0,
    1,1,0,1,1,1,1,0,
    1,0,0,0,0,0,0,0,
    1,0,1,1,1,1,1,0,
    1,1,1,1,1,1,1,0
  };
  for(uint8_t i=0; i<64; ++i)
  {
    level[i] = leveldata[i];
  };
  for(uint8_t i=0; i<16; ++i)
  {
    chests[i].set(0,0,0);
  }

  chests[0].set(0,1,1);
  chests[1].set(1,6,1); 
}

void World::load(uint8_t *ID) //reads a map from PROGMEM and loads it into memory
{
  /*
  width = pgm_read_byte(*ID);
  height = pgm_read_byte(*ID+1);

  player.x = pgm_read_byte(*ID+2);
  player.y = pgm_read_byte(*ID+3);

  int length = width*height;
  for(i=0; i<length; ++i)
  {
    level[i] = pgm_read_byte((*ID+4)+i);
  }
  */
}

bool World::validSize(const uint8_t width, const uint8_t height)  //will our world fit in RAM? Probably unneeded if the maps are precomputed
{
  return (width*height <= 256);
}

void World::set(const int8_t x, const int8_t y, const uint8_t wall)
{
  if(inbound(x,y))
    level[(y*width)+x] = wall;
}

void World::setFast(const int8_t x, const int8_t y, const uint8_t wall)
{
  level[(y*width)+x] = wall;
}

uint8_t World::get(const int8_t x, const int8_t y) const
{
  if(inbound(x,y))
    return level[(y*width)+x];
  else
    return 1;  //outside the map is a sea of walls
}
uint8_t World::getFast(const int8_t x, const int8_t y) const
{
  return level[(y*width)+x];
}
uint8_t World::getItem(const int8_t x, const int8_t y)
{
  //this is horrible please change
  for(uint8_t i; i<16; ++i) //loop every chest
  {
    if ((chests[i].getX() == x) && (chests[i].getY() == y)) //if chest is on position, return contents
      return (chests[i].getType()==false);
  }
}

bool World::inbound(const int8_t x, const int8_t y) const
{
  return((x>=0)&&(y>=0)&&(x<width)&&(y<height));
}

void World::step(void)
{

}