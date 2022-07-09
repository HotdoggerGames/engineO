#pragma once

#include <string>

#include "Math.h"

class Physics_Force
{
	public:
		Physics_Force(float p_x, float p_y, std::string p_name);
		Vector2 direction;
		std::string Name;
};