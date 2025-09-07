#pragma once
#include "IAllocatorOverlay.h"
#include "imgui.h"

namespace Allocators
{
    class CommonAllocatorOverlay : public IAllocatorOverlay
    {
        public:
            CommonAllocatorOverlay() = default;
            ~CommonAllocatorOverlay() = default;

            void RenderOverlay() override;
            
            bool IsVisible() const noexcept { return m_Visible; }

            void ChangeVisibility() noexcept { m_Visible = !m_Visible; }

            void RenderCommonOverlay();
        private:

            void CommonOverlayDataRender();

            bool m_Visible { false };
    };
} // namespace Allocators