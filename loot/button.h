#pragma once
#include <stdint.h>
#include "core/core.h"

enum class Button : uint8_t
{
	None = 0,
	Up = (UP_BUTTON),
	Down = (DOWN_BUTTON),
	Left = (LEFT_BUTTON),
	Right = (RIGHT_BUTTON),
	A = (A_BUTTON),
	B = (B_BUTTON),
	All = 
	(UP_BUTTON) | (DOWN_BUTTON) |
	(LEFT_BUTTON) | (RIGHT_BUTTON) |
	(A_BUTTON) | (B_BUTTON)
};
