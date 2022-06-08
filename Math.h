#pragma once
#include <iostream>

class Vector2
{
public:
	Vector2(float p_x, float p_y)
		:x(p_x), y(p_y)
	{};
	void print();
	
	float x, y;
private:
};