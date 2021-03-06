#include "fighter.h"
#include "enemytype.h"

Fighter::Fighter(const EnemyType type,const int8_t hp)
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