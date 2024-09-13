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

    void gui_handler::render_ui()
    {
        if (!_initialized)
            return;

        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

         ImGui::ShowDemoWindow();
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("ROM"))
            {
                if (ImGui::MenuItem("Load ROM"))
                {

                }
                if (ImGui::MenuItem("Close ROM"))
                {

                }

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Exit"))
            {
                _signals.exit_clicked = true;
                ImGui::EndMenu();
            }

            ImGui::EndMainMenuBar();
        }

        ImGui::Render();
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
    }

    gui_signals gui_handler::check_signals() const
    {
        return _signals;
    }

}
