#pragma once
#include "entity.h"
#include "RenWin.h"

class Player
{
	public:
		Player(Vector2 p_pos, SDL_Texture* p_tex);
		Player(Vector2 p_pos, SDL_Texture* p_tex, float p_min, float p_max);
		float getX();
		void setX(float p_x);
		float getY();
		void setY(float p_y);
		Vector2& getPos();
		SDL_Texture* getTex();
		void setTex(SDL_Texture* p_tex);
		SDL_Rect getCurFrame();
		bool update(SDL_Texture* p_frame_0, SDL_Texture* p_frame_1);
		void move(float xIn, float yIn, float speed);
		entity ent;
	private:
		Vector2 pos;
		SDL_Rect curFrame;
		SDL_Texture* tex;
		bool a;
		float frame;
		float max;
		float min;
};