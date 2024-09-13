#ifndef JUMI_JPOCKET_GUI_HANDLER_H
#define JUMI_JPOCKET_GUI_HANDLER_H

struct SDL_Window;
struct SDL_Renderer;

namespace JPocket
{

    struct gui_signals
    {
        bool exit_clicked = false;
    };

    class gui_handler
    {
    public:
        gui_handler();
        ~gui_handler();

        void init(SDL_Window* window, SDL_Renderer* renderer);
        void render_ui();
        [[nodiscard]] gui_signals check_signals() const;

    private:
        bool _initialized;
        gui_signals _signals;
    };

}

#endif

