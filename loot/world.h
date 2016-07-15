#pragma once
#include <stdint.h>
#include "list.h"
#include "itemtype.h"

// Chest needs its own file
class Chest
{
private:
    // Any time you think you should be storing any sort of 'type' as an integer:
    // stop yourself,
    // read this: http://www.cprogramming.com/c++11/c++11-nullptr-strongly-typed-enum-class.html,
    // and promptly create a new file with a nicely defined enum class
    ItemType type;
    int8_t x,y;

public:
    Chest(void) = default;
    Chest(const int8_t x, const int8_t y, const ItemType type); 
    void setType(const ItemType type); // I find the presence of only 1 set odd, but oh well
    void setPos(const int8_t x, const int8_t y);    //boom, there you go
    ItemType getType(void) const;
    int8_t getX(void) const;
    int8_t getY(void) const;
};

using ChestList = List<Chest, 16>;

class World
{
  public:
    uint8_t width,height;
    uint8_t level[128]; //biggest map size, 16*16, 32*8, etc
    ChestList chests;
    uint8_t itemType[16];
    uint8_t itemAction[16]; // I don't even want to know how an arbitrary number is supposed to represent an action

    void init(void);
    void step(void);
    void load(uint8_t *ID);
    void set(const int8_t x, const int8_t y, const uint8_t wall);
    void setFast(const int8_t x, const int8_t y, const uint8_t wall);
    bool validSize(const uint8_t width, const uint8_t height);
    uint8_t get(const int8_t x, const int8_t y) const;
    uint8_t getFast(const int8_t x, const int8_t y) const;
    bool inbound(const int8_t x, const int8_t y) const;

    //stupid
    void setItem(const uint8_t item, const int8_t x, const int8_t y, const ItemType type);
    ItemType getItemType(const int8_t x, const int8_t y);
    uint8_t getItemID(const int8_t x, const int8_t y);
    // This should be 'hasItem',
    // 'getItem' implies you can actually retrieve a reference to said item
    bool hasItem(const int8_t x, const int8_t y);
    //stupid
};
