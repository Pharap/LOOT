#include "battle.h"
#include "enemytype.h"
#include "fighter.h"

Battle::Battle(System & ab)
{
	this->ab = &ab;
}

void Battle::step(void)
{

}

void Battle::draw(void)
{
	ab->setCursor(64,0);
	ab->print(F("BATTLE!"));
}

