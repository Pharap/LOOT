#include "game.h"
#include "system.h"
#include "render.h"
#include "battle.h"
#include "menu.h"
#include "player.h"
#include "world.h"
#include "constants.h"
#include "direction.h"
#include "button.h"

Game::Game(System & ab, Render & render, Menu & menu, Player & player, World & world, Battle & battle)
{
  this->ab = &ab;
  this->menu = &menu;
  this->render = &render;
  this->player = &player;
  this->world = &world;
  this->battle = &battle;
}


void Game::save(const bool slot)
{

}
void Game::load(const bool slot)
{

}

void Game::step(void)
{
  if (ab->stateChanged())
  {
    auto state = ab->getState();
    switch(state)
    {
      case stateMenu:
      {
        menu->init();
        break;
      }
      case stateGame:
      {
        if (ab->getLastState() == stateMenu)
        {
          player->init();
          world->init();
          break;
        }
      }
      case stateBattle:
      {
      }
    }
  }
  ab->stateEndChange();

  switch(ab->getState())
  {
    case stateMenu:
    {
      menu->step();
      menu->draw();
      break;
    }
    case stateGame:
    {
      player->step();
      render->step();
      render->draw();
      player->resetMoved();
      break;
    }
    case stateBattle:
    {
      battle->step();

      render->drawView();
      battle->draw();
      break;
    }
  }
}
