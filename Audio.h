#pragma once
#include <SDL.h>
#include <string>
#include <SDL_Mixer.h>

Mix_Music* loadMus(const char* p_file)
{
	Mix_Music* mix = Mix_LoadMUS(p_file);
	if (mix == NULL)
	{
		std::cout << "FUCK No audio" << std::endl;
	}
	return mix;
}
