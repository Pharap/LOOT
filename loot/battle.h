#pragma once
#include <stdint.h>
#include "enemytype.h"

class Fighter
{
private:
	int8_t hp;
	const uint8_t * sprite;
public:
	Fighter(EnemyType, int8_t hp);
	int8_t getHp();
	void setHp(const int8_t hp);
	void setSprite();
}

class Battle
{
private:
	System * ab;
	Fighter player;
	Fighter enemy;

public:
	Battle(System & ab);

	void begin(void);
	void step(void);
	void draw(void);
}
