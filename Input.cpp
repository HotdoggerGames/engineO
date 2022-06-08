#include "Input.h"

float Input::getVertical(SDL_Event event, float p_y)
{
	if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN)
	{
		p_y = 1.0f;
	};
	if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_UP)
	{
		p_y = -1.0f;
	};

	return p_y;
};
float Input::getHorizontal(SDL_Event event, float p_x)
{
		if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
		{
			p_x = 1.0f;
		};
		if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_LEFT)
		{
			p_x = -1.0f;
		};

	return p_x;
};
bool Input::getKey(SDL_Event event, SDL_KeyCode p_key)
{
	if (event.key.keysym.sym == p_key)
	{
		return true;
	}
	else
	{
		return false;
	};
}