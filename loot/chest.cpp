#include "chest.h"
#include "itemtype.h"

Chest::Chest(const int8_t x, const int8_t y, const ItemType type)
{
  this->x = x;
  this->y = y;
  this->type = type;
}

ItemType Chest::getType() const
{
  return type;
}

void Chest::setType(const ItemType type)
{
  this->type = type;
}

int8_t Chest::getX() const
{
  return x;
}

void Chest::setX(const int8_t x)
{
  this->x = x;
}

int8_t Chest::getY() const
{
  return y;
}

void Chest::setY(const int8_t y)
{
  this->y = y;
}
