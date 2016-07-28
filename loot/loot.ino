#include <stdint.h>
#include <Arduboy.h>
#include "system.h"
#include "game.h"
#include "graphics.h"
#include "render.h"
#include "world.h"
#include "player.h"
#include "menu.h"
#include "battle.h"

System ab = System();
World world = World();
Battle battle = Battle(ab);
Player player = Player(ab, world);
Menu menu = Menu(ab);
Render render = Render(ab, world, player);
Game game = Game(ab, render, menu, player, world, battle); //controls everything!

void setup(void)
{
	ab.begin();
	Serial.begin(9600);
	Serial.println(F("Start!"));
}

void loop(void)
{
	if(!ab.nextFrame())
		return;

	ab.update();
	ab.clear();
	game.step();
	ab.display();
}
