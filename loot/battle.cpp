#include "battle.h"
#include "enemytype.h"
#include "fighter.h"

Battle::Battle(System & ab)
{
	this->ab = &ab;
}

void Battle::step(void)
{
	if(ab->isPressed(Button::A))
	{
		ab->setState(stateGame);
	}
}

void Battle::draw(void)
{
	ab->setCursor(64,0);
	ab->print(F("BATTLE!"));
}

void Battle::start(void)
{
	
}
