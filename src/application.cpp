#include "application.h"
#include "window_handler.h"
#include "window_specification.h"
#include "gui_handler.h"
#include <SDL2/SDL.h>
#include <imgui_impl_sdl2.h>
#include <iostream>

namespace JPocket
{

    application::application()
        : _window_specification()
        , _window_handler(_window_specification)
        , _gui()
        , _running(true)
    {
        _gui.init(_window_handler.window(), _window_handler.renderer());

        {
            // Here is where we get the main menu bar height from ImGui so we can resize the main window
            _gui.prepare_ui();
            _gui.render_ui();
            float menu_height = _gui.get_menubar_height();

            // Don't scale the menu height with the graphics scalar
            int width = _window_specification.width * _window_specification.scalar;
            int height = (_window_specification.height * _window_specification.scalar) + menu_height;

            _window_handler.set_window_size(width, height);
        }

        _window_handler.show_window();
    }

    int application::run()
    {
        while (_running)
        {
            _window_handler.clear_framebuffer();
            _gui.prepare_ui();
            _gui.render_ui();
            _window_handler.render();

            poll_gui_signals();

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

    void application::poll_gui_signals()
    {
        gui_signals signals = _gui.check_signals();
        if (signals.exit_clicked)
        {
            _running = false;
            return;
        }
    }

}
