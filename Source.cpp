#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "entity.h"
#include "RenWin.h"
#include "utils.h"
#include "Input.h"
#include "Player.h"


int main(int argc, char* args[])
{
	std::cout << "TESTING!" << std::endl;

	std::cout << "SUCCESS" << std::endl;

	RenWin window("GAME v1.0", 1280, 720);

	SDL_Texture* GhostTex_0 = window.loadTexture("resources/ghost-0.png");
	SDL_Texture* GhostTex_1 = window.loadTexture("resources/ghost-1.png");
	SDL_Texture* Tex = window.loadTexture("resources/reflect potate.png");

	//entity ghost(100,84,GhostTex);
	//entity potate(100,100,Tex);
	//entity entities[2] = {entity(100,100,Tex), entity(100,84,GhostTex) };
	std::vector<entity> entities = { entity(Vector2(0,0),Tex), entity(Vector2(100,100),Tex), entity(Vector2(100,160),Tex) , entity(Vector2(100,440),Tex) };
	Player ghost(Vector2(100, 100), GhostTex_0, 0, 10);
	bool Gaming = true;

	SDL_Event event;
	Input input;
	const float timeStep = 0.05f;
	float accumulator = 0.0f;
	float currentTime = utils::hireTimeInSecondes();
	float xIn = 1.0f;
	float yIn = 1.0f;
	float speed = 2.5f;

	while (Gaming)
	{	
		ghost.update(GhostTex_1, GhostTex_0);
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
				if (event.type == SDL_KEYDOWN)
				{
					/*if (xIn == 1.0f)
					{
						ghost.setX(ghost.getX() + speed * xIn);
					};
					if (xIn == -1.0f)
					{
						ghost.setX(ghost.getX() + speed * xIn);
					};
					if (yIn == 1.0f)
					{
						ghost.setY(ghost.getY() + speed * yIn);
					};
					if (yIn == -1.0f)
					{
						ghost.setY(ghost.getY() + speed * yIn);
					};*/
					ghost.move(xIn, yIn, speed);
				};
				
			};
			accumulator -= timeStep;
		};

		const float alpha = accumulator / timeStep;
		
		window.clear();
		//window.render(potate);
		for (entity& e : entities) 
		{
			if (e.getX() + (48) >= ghost.getX() && e.getX() + (48) <= (ghost.getX() + (ghost.getCurFrame().w * 6)) && e.getY() + (48) >= ghost.getY() && e.getY() + (48) <= (ghost.getY() + (ghost.getCurFrame().h * 6)))
			{
				std::cout << "colliding" << utils::hireTimeInSecondes() << std::endl;
			}
			window.render(e);
		}
		window.render(ghost.ent);

		window.display();
	};

	window.cleanUp();
	SDL_Quit();

	return 0;
};