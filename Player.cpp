#include "Player.h"
#include "Math.h"
#include "entity.h"
#include "RenWin.h"

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

Player::Player(Vector2 p_pos, SDL_Texture* p_tex)
	:tex(p_tex), pos(p_pos), frame(0.0f), ent(entity(Vector2(NULL,NULL),NULL,"None"))
{
	curFrame.x = 8;
	curFrame.y = 8;
	curFrame.w = 16;
	curFrame.h = 16;
}
Player::Player(Vector2 p_pos, SDL_Texture* p_tex, float p_min, float p_max)
	:tex(p_tex), pos(p_pos), frame(0.0f), min(p_min), max(p_max), ent(entity(Vector2(NULL,NULL),NULL, "None"))
{
	curFrame.x = 8;
	curFrame.y = 8;
	curFrame.w = 16;
	curFrame.h = 16;
}
float Player::getX()
{
	return pos.x;
}
void Player::setX(float p_x)
{
	pos.x = p_x;
}
float Player::getY()
{
	return pos.y;
}
void Player::setY(float p_y)
{
	pos.y = p_y;
}
Vector2& Player::getPos()
{
	return pos;
}
SDL_Texture* Player::getTex()
{
	return tex;
}
void Player::setTex(SDL_Texture* p_tex)
{
	tex = p_tex;
}
SDL_Rect Player::getCurFrame()
{
	return curFrame;
}
bool Player::update(SDL_Texture* p_frame_0, SDL_Texture* p_frame_1)
{
	if (frame == max)
	{
		a = false;
	}
	if (frame == min)
	{
		a = true;
	};
	if (frame >= min && a == true)
	{
		tex = p_frame_1;
		frame++;
	}
	if (frame <= max && a == false)
	{
		tex = p_frame_0;
		frame--;
	};
	ent.setX(pos.x);
	ent.setY(pos.y);
	ent.setTex(tex);
	return true;
}

void Player::move(float xIn, float yIn, float speed)
{
	if (xIn == 1.0f)
	{
		setX(getX() + speed * xIn);
	};
	if (xIn == -1.0f)
	{
		setX(getX() + speed * xIn);
	};
	if (yIn == 1.0f)
	{
		setY(getY() + speed * yIn);
	};
	if (yIn == -1.0f)
	{
		setY(getY() + speed * yIn);
	};
}
void Player::move(float xIn, float yIn, float speed, bool colliding, entity entity)
{
	if (xIn == 1.0f && colliding == false && entity.getX() < getX() || xIn == 1.0f && colliding == true && entity.getX() > getX() + (48))
	{
		setX(getX() + speed * xIn);
	};
	if (xIn == -1.0f && colliding == false && entity.getX() + (48) < getX() || xIn == -1.0f && colliding == true && entity.getX() > getX())
	{
		setX(getX() + speed * xIn);
	};
	if (yIn == 1.0f && colliding == false && entity.getY() < getY() || yIn == 1.0f && colliding == true && entity.getY() + (48) > getY())
	{
		setY(getY() + speed * yIn);
	};
	if (yIn == -1.0f && colliding == false && entity.getY() + (48) < getY() || yIn == -1.0f && colliding == true && entity.getY() > getY())
	{
		setY(getY() + speed * yIn);
	};
}
