#ifndef JUMI_JPOCKET_GUI_HANDLER_H
#define JUMI_JPOCKET_GUI_HANDLER_H

struct SDL_Window;
struct SDL_Renderer;

namespace JPocket
{

    struct gui_signals
    {
        bool load_rom     = false;
        bool close_rom    = false;
        bool exit_clicked = false;
    };

    class gui_handler
    {
    public:
        gui_handler();
        ~gui_handler();

        void init(SDL_Window* window, SDL_Renderer* renderer);
        void prepare_ui();
        void render_ui();
        [[nodiscard]] gui_signals check_signals() const;
        [[nodiscard]] float get_menubar_height() const;

    private:
        bool _initialized;
        float _menubar_height;
        gui_signals _signals;
    };

}

#endif

