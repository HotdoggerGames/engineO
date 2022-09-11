#pragma once
#include "Physics_Force.h"
#include "Math.h"
#include "Entity.h"

#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

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
		void setCurFrame(SDL_Rect p_frame);
		bool update(entity e);
		bool AnimUpdate(std::vector<SDL_Rect> p_array);
		bool PhysUpdate();
		void move(float xIn, float yIn, float speed);
		void AddForce(float p_x, float p_y, std::string p_name);
		void RemoveForce(std::string p_name);
		std::vector<Physics_Force> Forces;
		int vY;
	private:
		Vector2 pos;
		SDL_Rect curFrame;
		bool a = true;
		bool c = false;
		int b = 0;
		int max;
		int jh = 50;
		SDL_Texture* tex;
		int frame;

};