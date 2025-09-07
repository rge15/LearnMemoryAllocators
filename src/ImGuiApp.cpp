#include "ImGuiApp.h"
#include "GraphicsLayer.h"
#include <string>
#include "imgui.h"
#include "TempUIAllocator.h"
#include "BasicAllocatorOverlay.h"
#include <cxxabi.h>
#include "MemoryViewer.h" 

namespace Graphics
{
    ImGuiApp::ImGuiApp(GraphicsContext& graphicsContext) noexcept
        : m_GraphicsContext{ graphicsContext }
        , m_showAllocatorsMenu { false }
    {
        m_Overlays.push_back(std::make_unique<Allocators::TempUIAllocator>());
        m_Overlays.push_back(std::make_unique<Allocators::BasicAllocatorOverlay>());
    }

    void ImGuiApp::Render() noexcept
    {
        RenderMenuOptions();
        RenderOverlays();
        RenderWindows();
    }

    void ImGuiApp::RenderMenuOptions() noexcept
    {
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("Allocators"))
            {
                int overlayNum = 0;
                for(auto& overlay : m_Overlays )
                {
                    std::string const overlayName = typeid(*overlay.get()).name();
                    char const * const demangledOverlayName = abi::__cxa_demangle(overlayName.c_str(),nullptr,nullptr,nullptr);
                    std::string overlayShortcut = "Ctrl+";
                    overlayShortcut += std::to_string(overlayNum);
                    
                    if( overlayNum > 9 )
                    {
                        overlayShortcut = "";
                    }

                    if(ImGui::MenuItem(demangledOverlayName, overlayShortcut.c_str()))
                    {
                        overlay->ChangeVisibility();
                    }

                    ++overlayNum;
                }
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Windows"))
            {
                if(ImGui::MenuItem("Memory View", "Ctrl+M"))
                {
                    MemoryViewer::GetInstance().ChangeVisibility();
                }

                ImGui::EndMenu();
            }

            ImGui::EndMainMenuBar();
        }
    }

    void ImGuiApp::RenderOverlays() noexcept
    {
        for(auto& overlay : m_Overlays )
        {
            if(overlay->IsVisible())
            {
                overlay->RenderCommonOverlay();
            }
        }
    }

    void ImGuiApp::RenderWindows() noexcept
    {
        MemoryViewer & memoryViewer = MemoryViewer::GetInstance();
        if(memoryViewer.IsVisible())
        {
            memoryViewer.Render();
        }
    }

}