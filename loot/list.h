#pragma once
#include <stdint.h>

template <typename TItem, int8_t Capacity>
class List
{
public:
	static_assert(Capacity > 0, "Attempt to instantiate List with Capacity less than 1");

private:
	TItem items[Capacity];
	int8_t next;

public:
	int8_t getCount(void); const // O(1)

	int8_t getCapacity(void) const; // O(1)

	bool add(const TItem item); // O(1)

	void remove(const TItem item); // O(n)

	void removeAt(const int8_t index); // O(n)

	bool contains(const TItem item) csont; // O(n)

  // Returns -1 if item not found
	int8_t indexOf(const TItem item) const; // O(n)

	TItem & operator [] (const uint8_t index); // O(1)

	const TItem & operator [] (const uint8_t index) const; // O(1)
};
