#pragma once
#include <stdint.h>

class Chest {
private:
    uint8_t type;
    int8_t x,y;

public:
    void set(int8_t x, int8_t y, uint8_t type); 
    void setType(uint8_t type);
    uint8_t getType();
    int8_t getX();
    int8_t getY();
};

class World
{
  public:
    uint8_t width,height;
    uint8_t level[128]; //biggest map size, 16*16, 32*8, etc
    Chest chests[16];
    uint8_t itemType[16];
    uint8_t itemAction[16];

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
    void setItem(const uint8_t item, const int8_t x, const int8_t y, const uint8_t type);
    uint8_t getItemType(const int8_t x, const int8_t y);
    uint8_t getItemID(const int8_t x, const int8_t y);
    bool getItem(const int8_t x, const int8_t y);
    //stupid
};
