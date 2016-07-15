#pragma once
#include <stdint.h>

class System;
class Render;
class Menu;
class World;
class Player;
class Battle;

class Game
{
  private:
    System * ab;
    Render * render;
    Menu * menu;
    World * world;
    Player * player;
    Battle * battle;

  public:
    Game(System & ab, Render & render, Menu & menu, Player & player, World & world, Battle & battle);

    void step(void);
    void draw(void);
    void load(const bool slot);
    void save(const bool slot);
};
