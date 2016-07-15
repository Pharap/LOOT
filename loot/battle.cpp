#include "battle.h"
#include "enemytype.h"

Fighter::Fighter(EnemyType type, int8_t hp);
{
	this->type = type;
	this->hp = hp;
}

void Fighter::setHP(const int8_t hp)
{
	this->hp = hp;
}

int8_t Fighter::getHP()
{
	return this->hp;
}

