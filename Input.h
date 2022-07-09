#pragma once

#include <SDL.h>

class Input
{
	public:
		float getVertical(SDL_Event event, float p_y);
		float getHorizontal(SDL_Event event, float p_x);
		bool getKey(SDL_Event event, SDL_KeyCode p_key);
};