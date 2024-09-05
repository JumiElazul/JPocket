#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
        __debugbreak();

	SDL_Window* window = SDL_CreateWindow("JPocket", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_HIDDEN);
	SDL_ShowWindow(window);

	unsigned int time = 0;
	while (time < 1000)
	{
		time = SDL_GetTicks();
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
