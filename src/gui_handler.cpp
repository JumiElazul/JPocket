#include "gui_handler.h"
#include "resources.h"
#include "typedefs.h"
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <filesystem>

namespace JPocket
{

    gui_handler::gui_handler()
        : _initialized(false)
        , _menubar_height()
        , _signals()
    {

    }

    gui_handler::~gui_handler()
    {
        if (_initialized)
        {
            ImGui_ImplSDLRenderer2_Shutdown();
            ImGui_ImplSDL2_Shutdown();
            ImGui::DestroyContext();
        }
    }

    void gui_handler::init(SDL_Window* window, SDL_Renderer* renderer)
    {
        if (!_initialized)
        {
            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGuiIO& io = ImGui::GetIO(); (void)io;

            bool custom_font_exists = std::filesystem::exists(resources::font_path);
            JUMI_ASSERT(custom_font_exists);
            io.Fonts->AddFontFromFileTTF(resources::font_path, 16.0f);

            io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

            ImGui::StyleColorsDark();
            ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
            ImGui_ImplSDLRenderer2_Init(renderer);

            _initialized = true;
        }
    }

    void gui_handler::prepare_ui()
    {
        if (!_initialized)
            return;

        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        _signals = gui_signals();

        //ImGui::ShowDemoWindow();
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("ROM"))
            {
                if (ImGui::MenuItem("Load ROM"))
                {
                    _signals.load_rom = true;
                }
                if (ImGui::MenuItem("Close ROM"))
                {
                    _signals.close_rom = true;
                }

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Exit"))
            {
                _signals.exit_clicked = true;
                ImGui::EndMenu();
            }

            _menubar_height = ImGui::GetFrameHeight();
            ImGui::EndMainMenuBar();
        }
    }

    void gui_handler::render_ui()
    {
        ImGui::Render();
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
    }

    gui_signals gui_handler::check_signals() const
    {
        return _signals;
    }

    float gui_handler::get_menubar_height() const
    {
        return _menubar_height;
    }

}
