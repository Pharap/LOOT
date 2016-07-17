#include <stdint.h>
#include <Arduboy.h>
#include "system.h"
#include "game.h"
#include "graphics.h"
#include "constants.h"
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
	ab.fillScreen(0);
  	ab.drawSpriteCentred(System::ScreenCentreX, System::ScreenCentreY, imgTitle, 1);
	ab.display();
	while(!ab.isPushed(Button::A))	//keep titlescreen up until a button is pressed
	{
		ab.update();
	}
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
