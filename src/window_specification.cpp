#include "window_specification.h"
#include <SDL2/SDL.h>

namespace JPocket
{

    window_specification::window_specification()
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

}

