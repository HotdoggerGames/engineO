#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RenWin.h"

RenWin::RenWin(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w , p_h, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "FUCK No window";
	}
	 
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
};
RenWin::RenWin(const char* p_title, int p_w, int p_h, int p_x, int p_y)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, p_x, p_y, p_w , p_h, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "FUCK No window";
	}
	 
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
};

SDL_Texture* RenWin::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);
	if (texture == NULL)
	{
		std::cout << "FUCK No texture " << p_filePath << std::endl;
	}
	return texture;
}

void RenWin::cleanUp()
{
	SDL_DestroyWindow(window);
}
void RenWin::clear()
{
	SDL_RenderClear(renderer);
}
void RenWin::render(entity& p_entity)
{
	SDL_Rect srcs;
	srcs.x = p_entity.getCurFrame().x;
	srcs.y = p_entity.getCurFrame().y;
	srcs.w = p_entity.getCurFrame().w;
	srcs.h = p_entity.getCurFrame().h;
	SDL_Rect dst;
	dst.x = p_entity.getX();
	dst.y = p_entity.getY();
	dst.w = p_entity.getCurFrame().w * 4;
	dst.h = p_entity.getCurFrame().h * 4;

	SDL_RenderCopy(renderer, p_entity.getTex(), &srcs, &dst);
}
void RenWin::render(entity& p_entity, float p_w, float p_h)
{
	SDL_Rect srcs;
	srcs.x = p_entity.getCurFrame().x;
	srcs.y = p_entity.getCurFrame().y;
	srcs.w = p_w;
	srcs.h = p_h;
	SDL_Rect dst;
	dst.x = p_entity.getX();
	dst.y = p_entity.getY();
	dst.w = p_entity.getCurFrame().w * 4;
	dst.h = p_entity.getCurFrame().h * 4;

	SDL_RenderCopy(renderer, p_entity.getTex(), &srcs, &dst);
}
void RenWin::render(Player& p_entity, float p_w, float p_h)
{
	SDL_Rect srcs;
	srcs.x = p_entity.getCurFrame().x;
	srcs.y = p_entity.getCurFrame().y;
	srcs.w = p_w;
	srcs.h = p_h;
	SDL_Rect dst;
	dst.x = p_entity.getX();
	dst.y = p_entity.getY();
	dst.w = p_entity.getCurFrame().w * 4;
	dst.h = p_entity.getCurFrame().h * 4;

	SDL_RenderCopy(renderer, p_entity.getTex(), &srcs, &dst);
}
void RenWin::display()
{
	SDL_RenderPresent(renderer);
}