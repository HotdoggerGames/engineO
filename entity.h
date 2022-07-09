#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "Math.h"

class entity
{
	public:
		entity(Vector2 p_pos, SDL_Texture* p_tex);
		entity(Vector2 p_pos, SDL_Texture* p_tex, std::string p_type);
		float getX();
		void setX(float p_x);
		float getY();
		void setY(float p_y);
		Vector2& getPos();
		SDL_Texture* getTex();
		void setTex(SDL_Texture* p_tex);
		SDL_Rect getCurFrame();
		void setCurFrame(SDL_Rect p_rect);
		std::string type;
	private:
		Vector2 pos;
		SDL_Rect curFrame;
		SDL_Texture* tex;
};
