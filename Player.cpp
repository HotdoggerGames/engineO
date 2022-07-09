#include "Player.h"
#include "Math.h"
#include "entity.h"
#include "RenWin.h"

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

Player::Player(Vector2 p_pos, SDL_Texture* p_tex, int p_max)
	:tex(p_tex), pos(p_pos), frame(0.0f), ent(entity(Vector2(NULL,NULL),NULL,"None")), max(p_max)
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

bool Player::update()
{
	ent.setX(pos.x);
	ent.setY(pos.y);
	ent.setTex(tex);
	return true;
}

bool Player::PhysUpdate()
{
	for (int i = 0; i < Forces.size(); i++)
	{
		pos.x += Forces[i].direction.x;
		pos.y -= Forces[i].direction.y;
	}
	return true;
}

bool Player::AnimUpdate(std::vector<SDL_Rect> p_array)
{
	if (b == max)
	{
		c = false;
	}
	if (b == 0)
	{
		c = true;
	};
	if (b >= 0 && c == true)
	{
		b++;
	}
	if (b <= max && c == false)
	{
		b--;
	};
	if (b == max)
	{
		if (frame == p_array.size() - 1)
		{
			a = false;
		}
		if (frame == 0)
		{
			a = true;
		};
		if (frame >= 0 && a == true)
		{
			frame++;
		}
		if (frame <= p_array.size() - 1 && a == false)
		{
			frame--;
		};
		ent.setCurFrame(p_array[frame]);
		//std::cout << frame << std::endl;
	}
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

void Player::AddForce(float p_x, float p_y, std::string p_name)
{
	Forces.push_back(Physics_Force(p_x, p_y, p_name));
}

void Player::RemoveForce(std::string p_name)
{
	for (int i = 0; i < Forces.size(); i++)
	{
		if (Forces[i].Name == p_name)
		{
			Forces.erase(Forces.begin() + i);
		}
	}
}
