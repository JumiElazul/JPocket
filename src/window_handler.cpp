#include "window_handler.h"
#include "gui_handler.h"
#include "typedefs.h"
#include <SDL2/SDL.h>

namespace JPocket
{

    void window_specification::set_window_flags()
    {
        // flags |= SDL_WINDOW_FULLSCREEN;             // Fullscreen window
        // flags |= SDL_WINDOW_OPENGL;                 // Window usable with OpenGL context
        // flags |= SDL_WINDOW_SHOWN;                  // Window is visible
        flags |= SDL_WINDOW_HIDDEN;                 // Window is not visible
        // flags |= SDL_WINDOW_BORDERLESS;             // No window decoration
        // flags |= SDL_WINDOW_RESIZABLE;              // Window can be resized
        // flags |= SDL_WINDOW_MINIMIZED;              // Window is minimized
        // flags |= SDL_WINDOW_MAXIMIZED;              // Window is maximized
        // flags |= SDL_WINDOW_MOUSE_GRABBED;          // Window has grabbed mouse input
        // flags |= SDL_WINDOW_INPUT_FOCUS;            // Window has input focus
        // flags |= SDL_WINDOW_MOUSE_FOCUS;            // Window has mouse focus
        // flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
        // flags |= SDL_WINDOW_FOREIGN;                // Window not created by SDL

        // flags |= SDL_WINDOW_ALLOW_HIGHDPI;          // Window should be created in high-DPI mode if support
                                                    //   On macOS NSHighResolutionCapable must be set true in the
                                                    //   application's Info.plist for this to have any effect.

        // flags |= SDL_WINDOW_MOUSE_CAPTURE;          // Window has mouse captured (unrelated to MOUSE_GRABBED)
        // flags |= SDL_WINDOW_ALWAYS_ON_TOP;          // Window should always be above others
        // flags |= SDL_WINDOW_SKIP_TASKBAR ;          // Window should not be added to the taskbar
        // flags |= SDL_WINDOW_UTILITY;                // Window should be treated as a utility window
        // flags |= SDL_WINDOW_TOOLTIP;                // Window should be treated as a tooltip
        // flags |= SDL_WINDOW_POPUP_MENU;             // Window should be treated as a popup menu
        // flags |= SDL_WINDOW_KEYBOARD_GRABBED;       // Window has grabbed keyboard input
        // flags |= SDL_WINDOW_VULKAN;                 // Window usable for Vulkan surface
        // flags |= SDL_WINDOW_METAL;                  // Window usable for Metal view

        // flags |= SDL_WINDOW_INPUT_GRABBED
    }


    window_handler::window_handler()
        : _window_spec()
        , _main_window()
        , _renderer()
        , _gui()
    {
        _window_spec.set_window_flags();

        _main_window = SDL_CreateWindow(
            _window_spec.title,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            _window_spec.width * _window_spec.scalar,
            _window_spec.height * _window_spec.scalar,
            _window_spec.flags
        );

        JUMI_ASSERT(_main_window);

        unsigned int renderer_flags = 0;
        renderer_flags                 |= SDL_RENDERER_ACCELERATED;
        if (_window_spec.vsync) renderer_flags |= SDL_RENDERER_PRESENTVSYNC;

        _renderer = SDL_CreateRenderer(
            _main_window,
            -1,
            renderer_flags
        );

        JUMI_ASSERT(_renderer);

        SDL_ShowWindow(_main_window);
        _gui.init(_main_window, _renderer);
    }

    window_handler::~window_handler()
    {
        if (_renderer)
            SDL_DestroyRenderer(_renderer);

        if (_main_window)
            SDL_DestroyWindow(_main_window);
    }

    void window_handler::clear_framebuffer() const
    {
        SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
        SDL_RenderClear(_renderer);
    }

    void window_handler::render()
    {
        _gui.render_ui();
        SDL_RenderPresent(_renderer);
    }

    gui_signals window_handler::check_signals()
    {
        return _gui.check_signals();
    }


}
