#include "entity.h"
#include "Math.h"

#include <SDL.h>
#include <SDL_image.h>
#include <string>

entity::entity(Vector2 p_pos, SDL_Texture* p_tex)
	:tex(p_tex), pos(p_pos)
{
	curFrame.x = 0;
	curFrame.y = 0;
	curFrame.w = 16;
	curFrame.h = 16;
}
entity::entity(Vector2 p_pos, SDL_Texture* p_tex, std::string p_type)
	:tex(p_tex), pos(p_pos), type(p_type)
{
	curFrame.x = 0;
	curFrame.y = 0;
	curFrame.w = 16;
	curFrame.h = 16;
}
float entity::getX()
{
	return pos.x;
}
void entity::setX(float p_x)
{
	pos.x = p_x;
}
float entity::getY()
{
	return pos.y;
}
void entity::setY(float p_y)
{
	pos.y = p_y;
}
Vector2& entity::getPos()
{
	return pos;
}
SDL_Texture* entity::getTex()
{
	return tex;
}
void entity::setTex(SDL_Texture* p_tex)
{
	tex = p_tex;
}
SDL_Rect entity::getCurFrame()
{
	return curFrame;
}
void entity::setCurFrame(SDL_Rect p_rect)
{
	curFrame = p_rect;
}