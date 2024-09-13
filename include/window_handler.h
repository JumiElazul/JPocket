#ifndef JUMI_JPOCKET_WINDOW_HANDLER_H
#define JUMI_JPOCKET_WINDOW_HANDLER_H
#include "gui_handler.h"

struct SDL_Window;
struct SDL_Renderer;

namespace JPocket
{

    struct window_specification
    {
        const char* title = "JPocket";
        int width = 160;
        int height = 144;
        float scalar = 4.0f;
        unsigned int flags = 0;
        bool vsync = true;

        void set_window_flags();
    };

    class window_handler
    {
    public:
        window_handler();
        ~window_handler();
        void clear_framebuffer() const;
        void render();

        [[nodiscard]] gui_signals check_signals();

    private:
        window_specification _window_spec;
        SDL_Window* _main_window;
        SDL_Renderer* _renderer;
        gui_handler _gui;
    };

}

#endif
