#pragma once
#include "entity.h"
#include "RenWin.h"
#include "Physics_Force.h"
#include "Math.h"

#include <vector>
#include <string>

class Player
{
	public:
		Player(Vector2 p_pos, SDL_Texture* p_tex, int max);
		float getX();
		void setX(float p_x);
		float getY();
		void setY(float p_y);
		Vector2& getPos();
		SDL_Texture* getTex();
		void setTex(SDL_Texture* p_tex);
		SDL_Rect getCurFrame();
		bool update();
		bool AnimUpdate(std::vector<SDL_Rect> p_array);
		bool PhysUpdate();
		void move(float xIn, float yIn, float speed);
		void AddForce(float p_x, float p_y, std::string p_name);
		void RemoveForce(std::string p_name);
		std::vector<Physics_Force> Forces;
		entity ent;
	private:
		Vector2 pos;
		SDL_Rect curFrame;
		bool a = true;
		bool c = false;
		int b = 0;
		int max;
		SDL_Texture* tex;
		int frame;

};