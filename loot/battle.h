#pragma once
#include <stdint.h>
#include "system.h"
#include "enemytype.h"
#include "fighter.h"

class Fighter;

class Battle
{
private:
	System * ab;
	uint8_t select;

public:
	Battle(System & ab);

	void step(void);
	void draw(void);
	void start(void);
};
