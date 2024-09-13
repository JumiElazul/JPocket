#include "window_handler.h"
#include "window_specification.h"
#include "gui_handler.h"
#include "typedefs.h"
#include <SDL2/SDL.h>

namespace JPocket
{

    window_handler::window_handler(const window_specification& spec)
        : _main_window()
        , _renderer()
    {
        JUMI_ASSERT(SDL_Init(SDL_INIT_VIDEO) == 0);

        // -------------------------------------------------------------------------------------------------------
        // The size of the window creation at this point doesn't matter - we are just initializating a base window
        // size for now until we can later get the height of the main menu bar.  At that point, the main menu will be
        // resized before being shown to the user to allow for the extra menu height space.
        _main_window = SDL_CreateWindow(
            spec.title,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            spec.width * spec.scalar,
            spec.height * spec.scalar,
            spec.flags
        );
        // -------------------------------------------------------------------------------------------------------

        JUMI_ASSERT(_main_window);

        unsigned int renderer_flags = 0;
        renderer_flags                 |= SDL_RENDERER_ACCELERATED;
        if (spec.vsync) renderer_flags |= SDL_RENDERER_PRESENTVSYNC;

        _renderer = SDL_CreateRenderer(
            _main_window,
            -1,
            renderer_flags
        );

        JUMI_ASSERT(_renderer);
    }

    window_handler::~window_handler()
    {
        if (_renderer)
            SDL_DestroyRenderer(_renderer);

        if (_main_window)
            SDL_DestroyWindow(_main_window);

        SDL_Quit();
    }

    void window_handler::set_window_size(int width, int height)
    {
        SDL_SetWindowSize(_main_window, width, height);
    }

    void window_handler::show_window(bool show) const
    {
        show ? SDL_ShowWindow(_main_window) : SDL_HideWindow(_main_window);
    }

    void window_handler::clear_framebuffer() const
    {
        SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
        SDL_RenderClear(_renderer);
    }

    void window_handler::render()
    {
        SDL_RenderPresent(_renderer);
    }

    SDL_Window* window_handler::window() const
    {
        return _main_window;
    }

    SDL_Renderer* window_handler::renderer() const
    {
        return _renderer;
    }

}
