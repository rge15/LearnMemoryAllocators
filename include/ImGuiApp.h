#pragma once
#include <memory>
#include <vector>
#include "CommonAllocatorOverlay.h"

namespace Graphics
{
    struct GraphicsContext;

    typedef std::unique_ptr<Allocators::CommonAllocatorOverlay> OverlayUniquePtr;

    class ImGuiApp
    {
        public:
            ImGuiApp() = delete;
            explicit ImGuiApp(GraphicsContext&) noexcept;

            void Render() noexcept;

        private:

            void RenderMenuOptions() noexcept;

            void RenderOverlays() noexcept;

            void RenderWindows() noexcept;

            GraphicsContext& m_GraphicsContext;

            std::vector<OverlayUniquePtr> m_Overlays;
            bool m_showAllocatorsMenu;
    };
} // namespace Graphics