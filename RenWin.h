#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "entity.h"
#include "Player.h"

class RenWin 
{
public:
	RenWin(const char* p_title, int p_w, int p_h);
	RenWin(const char* p_title, int p_w, int p_h, int p_x, int p_y);
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanUp();
	void clear();
	void render(entity& p_entity);
	void display();
	SDL_Renderer* renderer;
private:
	SDL_Window* window;
};