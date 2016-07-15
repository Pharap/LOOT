#pragma once
#include <stdint.h>
#include "system.h"
#include "enemytype.h"
//#include "fighter.h"

class Fighter;

class Battle
{
private:
	System * ab;
	//Fighter player;
	//Fighter enemy;

public:
	Battle(System & ab);

	void step(void);
	void draw(void);
	void start()
};
