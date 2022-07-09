#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include <vector>

#include "entity.h"
#include "RenWin.h"
#include "utils.h"
#include "Input.h"
#include "Player.h"
#include "Audio.h"
#include "Math.h"

int main(int argc, char* args[])
{
	std::cout << "TESTING!" << std::endl;
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	std::cout << "SUCCESS" << std::endl;
	RenWin window("GAME v1.0", 1280, 720);
	
	SDL_Texture* GhostTex = window.loadTexture("resources/ghost.png");
	SDL_Texture* Tex = window.loadTexture("resources/reflect potate.png");

	//entity ghost(100,84,GhostTex);
	//entity potate(100,100,Tex);
	//entity entities[2] = {entity(100,100,Tex), entity(100,84,GhostTex) };
	std::vector<entity> entities = { entity(Vector2(0,0),Tex), entity(Vector2(100,100),Tex,"Solid"),
		entity(Vector2(200,200),Tex,"Solid"), entity(Vector2(165,35),Tex,"Solid"),
		entity(Vector2(100,35),Tex,"Solid") , entity(Vector2(100,440),Tex)};
	Player ghost(Vector2(200, 100), GhostTex, 2);
	bool Gaming = true;
	Mix_Music* music_0 = Mix_LoadMUS("resources/o.wav");
	Mix_Music* music_1 = Mix_LoadMUS("resources/o.wav");
	Mix_Music* music_2 = Mix_LoadMUS("resources/o.wav");
	std::vector<SDL_Rect> ghost_anim;
	{
		SDL_Rect a;
		a.x = 0;
		a.y = 0;
		a.h = 16;
		a.w = 16;
		SDL_Rect b;
		b.x = 8;
		b.y = 0;
		b.h = 16;
		b.w = 16;
		SDL_Rect c;
		c.x = 16;
		c.y = 0;
		c.h = 16;
		c.w = 16;
		SDL_Rect d;
		d.x = 24;
		d.y = 0;
		d.h = 16;
		d.w = 16;
		ghost_anim.push_back(a);
		ghost_anim.push_back(b);
		ghost_anim.push_back(c);
		ghost_anim.push_back(d);
	}

	SDL_Event event;
	Input input;
	const float timeStep = 0.05f;
	float accumulator = 0.0f;
	float currentTime = utils::hireTimeInSecondes();
	float xIn = 1.0f;
	float yIn = 1.0f;
	float speed = 1.5f;
	entity ecol(Vector2(NULL, NULL), NULL, "None");
	Mix_PlayMusic(music_0, -1);

	while (Gaming)
	{
		window.clear();

		ghost.update();
		ghost.AnimUpdate(ghost_anim);
		float newTime = utils::hireTimeInSecondes();
		float frameTime = newTime - currentTime;

		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= timeStep)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					Gaming = false;
				};


				yIn = input.getVertical(event, 0.0f);
				xIn = input.getHorizontal(event, 0.0f);
				if (input.getKey(event, SDLK_1))
				{
					ghost.AddForce(0.25f, 0, "TEST");
				};
				if (input.getKey(event, SDLK_q))
				{
					ghost.AddForce(0, 0, "TEST");
					ghost.AddForce(0, 0, "TEST");
					ghost.AddForce(0, 0, "TEST");
					ghost.AddForce(0, 0, "TEST");
					ghost.AddForce(0, 0, "TEST");
				};
				if (input.getKey(event, SDLK_3))
				{
					ghost.AddForce(-0.25f, 0, "TEST");
				};
				if (input.getKey(event, SDLK_2))
				{
					ghost.RemoveForce("TEST");
				};
				if (input.getKey(event, SDLK_4))
				{
					Mix_HaltMusic();
				};
				if (input.getKey(event, SDLK_5))
				{
					Mix_HaltMusic();
					Mix_PlayMusic(music_2, -1);
				};
				if (input.getKey(event, SDLK_6))
				{
					Mix_HaltMusic();
					Mix_PlayMusic(music_0, -1);
				};
				if (input.getKey(event, SDLK_7))
				{
					Mix_HaltMusic();
					Mix_PlayMusic(music_1, -1);
				};
				ghost.move(xIn, yIn, speed);
				
			};
			accumulator -= timeStep;
		};
	for (entity& e : entities) 
	{
		bool colliding = false;
		if (e.getX() + (48) >= ghost.getX() && e.getX() + (48) <= (ghost.getX() + (ghost.getCurFrame().w * 6)) && e.getY() + (48) >= ghost.getY() && e.getY() + (48) <= (ghost.getY() + (ghost.getCurFrame().h * 6)) && e.type == "Solid")
		{
			colliding = true;
			if (colliding == true && e.getX() < ghost.getX())
			{
				ghost.setX(ghost.getX() + 8);
			};
			if (colliding == true && e.getX() + (48) > ghost.getX())
			{
				ghost.setX(ghost.getX() - 8);
			};
			if (colliding == true && e.getY() < ghost.getY())
			{
				ghost.setY(ghost.getY() + 16);
			};
			if ( colliding == true && e.getY() + (48) > ghost.getY())
			{
				ghost.setY(ghost.getY() - 16);
			};
		}

		e.setX(e.getX() + (xIn / 2));
		e.setY(e.getY() + (yIn / 2));

		window.render(e);
	}
	xIn = 0;
	yIn = 0;
		const float alpha = accumulator / timeStep;
		//window.render(potate);
		ghost.PhysUpdate();
		window.render(ghost.ent, 8, 8);
		ecol = entity(Vector2(-10000, -10000), NULL, "None");
		std::cout << ghost.Forces.size() << std::endl;
		window.display();
	};
	Mix_CloseAudio();
	Mix_FreeMusic(music_0);
	Mix_FreeMusic(music_1);
	Mix_FreeMusic(music_2);
	window.cleanUp();
	SDL_Quit();

	return 0;
};