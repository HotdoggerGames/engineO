#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "Math.h"

class entity
{
	public:
		entity(Vector2 p_pos, SDL_Texture* p_tex);
		float getX();
		void setX(float p_x);
		float getY();
		void setY(float p_y);
		Vector2& getPos();
		SDL_Texture* getTex();
		void setTex(SDL_Texture* p_tex);
		SDL_Rect getCurFrame();
	private:
		Vector2 pos;
		SDL_Rect curFrame;
		SDL_Texture* tex;
};
