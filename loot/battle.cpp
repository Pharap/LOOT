#include "battle.h"
#include "enemytype.h"
#include "fighter.h"
#include "gamestate.h"

Battle::Battle(System & ab)
{
	this->ab = &ab;
}

void Battle::step(void)
{
	if(ab->isPressed(Button::A))
	{
		ab->setState(GameState::Gameplay);
	}
}

void Battle::draw(void)
{
	ab->setCursor(System::ScreenCentreX, 0);
	ab->print(F("BATTLE!"));
}

void Battle::start(void)
{
	
}
