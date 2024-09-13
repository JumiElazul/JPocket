#include "application.h"
#include <SDL2/SDL.h>
#include <imgui_impl_sdl2.h>
#include <iostream>

namespace JPocket
{

    application::application()
        : _window_handler()
        , _running(true)
    {

    }

    int application::run()
    {
        while (_running)
        {
            _window_handler.clear_framebuffer();
            _window_handler.render();

            gui_signals signals = _window_handler.check_signals();
            if (signals.exit_clicked)
            {
                _running = false;
                break;
            }

            run_event_loop();
        }

        return 0;
    }

    void application::run_event_loop()
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            ImGui_ImplSDL2_ProcessEvent(&e);
            switch (e.type)
            {
                case SDL_KEYDOWN:
                {
                    SDL_Keycode code = e.key.keysym.sym;
                    if (code == SDLK_q) _running = false;
                } break;
            }
        }
    }

}
