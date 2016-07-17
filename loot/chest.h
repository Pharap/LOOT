#pragma once
#include <stdint.h>
#include "list.h"
#include "itemtype.h"

class Chest
{
private:
    ItemType type;
    int8_t x,y;

public:
    Chest(void) = default;
    Chest(const int8_t x, const int8_t y, const ItemType type);
    ItemType getType(void) const;
    void setType(const ItemType type);
    int8_t getX(void) const;
    void setX(const int8_t x);
    int8_t getY(void) const;
    void setY(const int8_t y);
};

using ChestList = List<Chest, 16>;
