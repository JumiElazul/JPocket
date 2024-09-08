#include <iostream>
#include <SDL2/SDL.h>

namespace JPocket
{
	int main(int argc, char* argv[])
	{
        const int MAX_CYCLES = 69905;

        const int SCREEN_WIDTH = 160;
        const int SCREEN_HEIGHT = 144;
        const float SCREEN_SCALAR = 4.0f;

        if (SDL_Init(SDL_INIT_VIDEO) < 0)
            return 1;

        SDL_Window* window = SDL_CreateWindow("JPocket",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH * SCREEN_SCALAR,
            SCREEN_HEIGHT * SCREEN_SCALAR,
            SDL_WINDOW_HIDDEN);

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
}

int main(int argc, char* argv[])
{
	return JPocket::main(argc, argv);
}
