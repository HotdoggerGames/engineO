#include "Player.h"
#include "Math.h"
#include "RenWin.h"

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

Player::Player(Vector2 p_pos, SDL_Texture* p_tex, int p_max)
	:tex(p_tex), pos(p_pos), frame(0.0f), max(p_max)
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

void Player::setCurFrame(SDL_Rect p_frame)
{
	curFrame = p_frame;
}

bool Player::update(entity e)
{
	/*
	ent.setX(pos.x);
	ent.setY(pos.y);
	ent.setTex(tex);*/
	if (e.getX() + (48) >= getX() && e.getX() + (48) <= (getX() + (getCurFrame().w * 6)) && e.getY() + (48) >= getY() && e.getY() + (48) <= (getY() + (getCurFrame().h * 6)) && e.type == "Solid")
	{
		if (e.getX() < getX())
		{
			setX(getX() + 8);
		};
		if (e.getX() + (48) > getX())
		{
			setX(getX() - 8);
		};
		if (e.getY() < getY())
		{
			setY(getY() + 16);
			vY -= 16;
		};
		if (e.getY() + (48) > getY())
		{
			setY(getY() - 16);
			vY += 16;
			jh = 50;
		};
	}
	return true;
}

bool Player::PhysUpdate()
{
	for (int i = 0; i < Forces.size(); i++)
	{
		pos.x += Forces[i].direction.x;
		pos.y -= Forces[i].direction.y;
		vY += Forces[i].direction.y / 2;
	};
	if (vY < 0)
	{
		vY = 0;
	};
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
		setCurFrame(p_array[frame]);
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
		if (jh > 0)
		{
			setY(getY() + speed * 2 * yIn * (jh / 10));
			jh -= speed;
		};
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
