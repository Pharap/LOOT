#include "game.h"
#include "system.h"
#include "render.h"
#include "battle.h"
#include "menu.h"
#include "player.h"
#include "world.h"
#include "direction.h"
#include "button.h"
#include "gamestate.h"

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
      case GameState::Menu:
      {
        menu->init();
        break;
      }
      case GameState::Gameplay:
      {
        if (ab->getLastState() == GameState::Menu)
        {
          player->init();
          world->init();
          break;
        }
      }
      case GameState::Battle:
      {
      }
    }
  }
  ab->stateEndChange();

  switch(ab->getState())
  {
    case GameState::Menu:
    {
      menu->step();
      menu->draw();
      break;
    }
    case GameState::Gameplay:
    {
      player->step();
      render->step();
      render->draw();
      player->resetMoved();
      break;
    }
    case GameState::Battle:
    {
      battle->step();

      render->drawView();
      battle->draw();
      break;
    }
  }
}
