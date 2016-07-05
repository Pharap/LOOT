#pragma once
#include <stdint.h>

class BitArray8
{
private:
    uint8_t value;
 
public:
    BitArray8(void) : value()
    {
    }
 
    BitArray8(const uint8_t value) : value(value)
    {
    }
 
    bool get(const uint8_t index) const
    {
        return (this->value & (1 << index)) != 0;
    }
 
    void set(const uint8_t index, const bool value)
    {
        if (value) set(index); else clear(index);
    }
 
    void set(const uint8_t index)
    {
        this->value |= (1 << index);
    }
 
    void clear(const uint8_t index)
    {
        this->value &= ~(1 << index);
    }
 
    BitArray8 & operator =(const uint8_t value)
    {
        this->value = value;
        return *this;
    }
 
    operator uint8_t(void) const
    {
        return this->value;
    }
};

class BitArray16
{
private:
    uint16_t value;
 
public:
    BitArray16(void) : value()
    {
    }
 
    BitArray16(const uint16_t value) : value(value)
    {
    }
    
    // using uint8_t for indices because [0, 15] < 255 and uin8_t is faster
    bool get(const uint8_t index) const
    {
        return (this->value & (1 << index)) != 0;
    }
 
    void set(const uint8_t index, const bool value)
    {
        if (value) set(index); else clear(index);
    }
 
    void set(const uint8_t index)
    {
        this->value |= (1 << index);
    }
 
    void clear(const uint8_t index)
    {
        this->value &= ~(1 << index);
    }
 
    BitArray16 & operator =(const uint16_t value)
    {
        this->value = value;
        return *this;
    }
 
    operator uint16_t(void) const
    {
        return this->value;
    }
};

template <uint8_t Size>
class BitArray
{
private:
	static_assert(Size < 255, "Size cannot exceed 254 elements");
	const uint8_t Count = (Size / 8) + (((Size % 8) > 0) ? 1 : 0);

private:
	BitArray8 values[(Size / 8) + (((Size % 8) > 0) ? 1 : 0)];

public:
	BitArray(void) : values()
	{
	}

	uint8_t getSize(void) const
	{
		return Size;
	}

	bool get(const uint8_t index) const
	{
		return this->values[index / 8].get(index % 8);
	}

	void set(const uint8_t index, const bool value)
	{
		return this->values[index / 8].set(index % 8, value);
	}

	void set(const uint8_t index)
	{
		return this->values[index / 8].set(index % 8);
	}

	void clear(const uint8_t index)
	{
		return this->values[index / 8].clear(index % 8);
	}
};
