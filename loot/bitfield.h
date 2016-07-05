#pragma once
#include <cstdint.h>

template <uint8_t Offset, uint8_t Mask>
class Bitfield8
{
private:
    uint8_t value;
 
public:
    Bitfield8 & operator =(const uint8_t value)
    {
        this->value = (this->value & ~Mask) | ((value << Offset) & Mask);
        return *this;
    }
 
    operator uint8_t(void) const
    {
        return (this->value & Mask) << Offset;
    }
};

template <uint16_t Offset, uint16_t Mask>
class Bitfield16
{
private:
    uint16_t value;
 
public:
    Bitfield16 & operator =(const uint8_t value)
    {
        this->value = (this->value & ~Mask) | ((value << Offset) & Mask);
        return *this;
    }
 
    Bitfield16 & operator =(const uint16_t value)
    {
        this->value = (this->value & ~Mask) | ((value << Offset) & Mask);
        return *this;
    }
 
    operator uint16_t(void) const
    {
        return (this->value & Mask) << Offset;
    }
};
