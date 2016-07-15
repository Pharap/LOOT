#include "battle.h"
#include "enemytype.h"
#include "fighter.h"
#include "constants.h"

Battle::Battle(System & ab)
{
	this->ab = &ab;
	start();
}

void Battle::start()
{
	//reset battle variables
	select = 0;
}

void Battle::step(void)
{
	if(ab->isPushed(Button::Up))
    {
      if(select > 0) --select;
    }
    if(ab->isPushed(Button::Down))
    {
      if(select < 2) ++select;
    }

    if(ab->isPushed(Button::A))
    {
    	switch(select)
    	{
    		case 2:
    		{
    			ab->setState(stateGame);
    		}
    	}
    }
}

void Battle::draw(void)
{

	ab->setCursor(72,0);
	ab->print(F("Fight"));
	ab->setCursor(72,8);
	ab->print(F("Items"));
	ab->setCursor(72,16);
	ab->print(F("Run"));

	ab->setCursor(64, (8 * select));
	ab->print(F(">"));
}

