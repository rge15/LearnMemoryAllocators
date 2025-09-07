#pragma once
#include "CommonAllocatorOverlay.h"

namespace Allocators
{
    class TempUIAllocator : public CommonAllocatorOverlay
    {
        void RenderOverlay() override;
    };
} // namespace Allocators
