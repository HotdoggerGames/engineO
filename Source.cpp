#include "CommonHeaders.h"

int main(int argc, char* args[])
{
	std::cout << "TESTING!" << std::endl;
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	std::cout << "SUCCESS" << std::endl;
	RenWin window("GAME v1.0", 1280, 720);
	SaveManager SM;
	
	SDL_Texture* GhostTex = window.loadTexture("resources/ghost.png");
	SDL_Texture* Tex = window.loadTexture("resources/reflect potate.png");

	//entity ghost(100,84,GhostTex);
	//entity potate(100,100,Tex);
	//entity entities[2] = {entity(100,100,Tex), entity(100,84,GhostTex) };
	std::vector<entity> entities;
	
	Player ghost(Vector2(200, 100), GhostTex, 2);
	bool Gaming = true;
	Mix_Music* music_0 = loadMus("resources/puzzle_1.wav");
	Mix_Music* music_1 = loadMus("resources/o.wav");
	Mix_Music* music_2 = loadMus("resources/o.wav");
	float level = SM.GetSave();
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

	int MouseX, MouseY;
	SDL_Event event;
	Input input;
	const float timeStep = 0.05f;
	float accumulator = 0.0f;
	float currentTime = utils::hireTimeInSecondes();
	float xIn = 1.0f;
	float yIn = 1.0f;
	float speed = 0.5f;
	Vector2 Origin = {0,0};
	entity ecol = entity(Vector2(NULL, NULL), NULL, "None");
	Mix_PlayMusic(music_0, -999);
	SDL_Texture* MouseTex = window.loadTexture("resources/reflect potate.png");
	ghost.AddForce(0, -1, "gravity");

	while (Gaming)
	{
		std::cout << "DEBUG: 03 " << "x:" << Origin.x;
		std::cout << " y:" << Origin.y << std::endl;
		std::vector<entity> Level0 = { entity(Vector2(0 + Origin.x,0 + Origin.y),Tex, "Mouse"), entity(Vector2(100 + Origin.x,100 + Origin.y) ,Tex,"Solid"),
		   entity(Vector2(200 + Origin.x,200 + Origin.y),Tex,"Solid"), entity(Vector2(165 + Origin.x,35 + Origin.y),Tex,"Solid"),
		   entity(Vector2(100 + Origin.x,35 + Origin.y),Tex,"Solid") , entity(Vector2(100 + Origin.x,440 + Origin.y),Tex, "Mouse") };
		std::vector<entity> Level1 = { entity(Vector2(0 + Origin.x,0 + Origin.y),Tex, "Mouse"), entity(Vector2(100 + Origin.x,100 + Origin.y) ,Tex,"Solid"),
		   entity(Vector2(350 + Origin.x,200 + Origin.y),Tex,"Solid"), entity(Vector2(165 + Origin.x,35 + Origin.y),Tex,"Solid"),
		   entity(Vector2(100 + Origin.x,35 + Origin.y),Tex,"Solid") , entity(Vector2(100 + Origin.x,440 + Origin.y),Tex, "Mouse") };
		std::vector<entity> Level2 = { entity(Vector2(0 + Origin.x,0 + Origin.y),Tex, "Mouse"), entity(Vector2(100 + Origin.x,100 + Origin.y) ,Tex,"Solid"),
		   entity(Vector2(0 + Origin.x,200 + Origin.y),Tex,"Solid"), entity(Vector2(165 + Origin.x,35 + Origin.y),Tex,"Solid"),
		   entity(Vector2(100 + Origin.x,35 + Origin.y),Tex,"Solid") , entity(Vector2(100 + Origin.x,440 + Origin.y),Tex, "Mouse") };
		SDL_GetMouseState(&MouseX, &MouseY);
		entity mouse(Vector2(MouseX - 8 * 4, MouseY - 8 * 4), MouseTex, "Solid");
		window.clear();
		if (entities.data() != Level0.data() && level == 0)
		{
			entities = Level0;
		};
		if (entities.data() != Level1.data() && level == 1)
		{
			entities = Level1;
		};
		if (entities.data() != Level2.data() && level == 2)
		{
			entities = Level2;
		};

		ghost.AnimUpdate(ghost_anim);
		float newTime = utils::hireTimeInSecondes();
		float frameTime = newTime - currentTime;

		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= timeStep)
		{
			while (SDL_PollEvent(&event))
			{
				if (input.getKey(event, SDLK_KP_0) || input.getKey(event, SDLK_KP_1) || input.getKey(event, SDLK_KP_2) || input.getKey(event, SDLK_KP_3) || input.getKey(event, SDLK_KP_4))
				{
					Gaming = false;
					std::cout << "ERROR: " << "01 MOUSE BROKE THINGS" << std::endl;
				};
				if (event.type == SDL_QUIT)
				{
					Gaming = false;
				};

				yIn = input.getVertical(event, 0.0f);
				xIn = input.getHorizontal(event, 0.0f);
				Origin.x -= xIn;
				if (yIn < 0)
				{
					ghost.vY -= yIn;
				}
				Origin.y = ghost.vY;
				if (input.getKey(event, SDLK_F1))
				{
					SM.SetSave("0");
					std::cout << level << std::endl;
				};
				if (input.getKey(event, SDLK_F2))
				{
					std::cout << "DEBUG: " << "01 F2 USED TO CRASH" << std::endl;\
					for (entity e : entities)
					{
						std::cout << "ARRAY: 01 " << "POSITION " + std::to_string(e.getX()) + ", " + std::to_string(e.getY()) << " TYPE & ID " << e.type << std::endl;
					}
					SM.SetSave("1");
					Gaming = false;
					return 0;
				};
				/*if (input.getKey(event, SDLK_1))
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
					Mix_PlayMusic(music_0, -1);
				};
				if (input.getKey(event, SDLK_6))
				{
					Mix_HaltMusic();
					Mix_PlayMusic(music_0, -1);
				};
				if (input.getKey(event, SDLK_7))
				{
					Mix_HaltMusic();
					Mix_PlayMusic(music_0, -1);
				};*/
				ghost.move(xIn, yIn, speed);
				
			};
			accumulator -= timeStep;
		};
	for (entity& e : entities)
	{/*bool colliding = false;
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
		}*/

			ghost.update(e);
			
			window.render(e, 16, 16);
		}
		xIn = 0;
		ghost.update(mouse);
		yIn = 0;
		const float alpha = accumulator / timeStep;
		//window.render(potate);
		ghost.PhysUpdate();
		window.render(ghost, 8, 8);
		window.render(mouse, 32, 32);
		ecol = entity(Vector2(-10000, -10000), NULL, "None");
		std::cout << "DEBUG: 02 " << ghost.Forces.size() << std::endl;
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