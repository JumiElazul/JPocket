#ifndef JUMI_JPOCKET_WINDOW_HANDLER_H
#define JUMI_JPOCKET_WINDOW_HANDLER_H
struct SDL_Window;
struct SDL_Renderer;

namespace JPocket
{
    struct window_specification;

    class window_handler
    {
    public:
        window_handler(const window_specification& spec);
        ~window_handler();
        void set_window_size(int width, int height);
        void show_window(bool show = true) const;
        void clear_framebuffer() const;
        void render();

        [[nodiscard]] SDL_Window* window() const;
        [[nodiscard]] SDL_Renderer* renderer() const;

    private:
        SDL_Window* _main_window;
        SDL_Renderer* _renderer;
    };

}

#endif
