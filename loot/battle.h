#pragma once
#include <stdint.h>
#include "system.h"
#include "enemytype.h"

class Fighter
{
private:
	int8_t hp;
	EnemyType type;
	const uint8_t * sprite;
public:
	Fighter(const EnemyType,const int8_t hp);
	int8_t getHP();
	void setHP(const int8_t hp);
	void setSprite();
};

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
};
