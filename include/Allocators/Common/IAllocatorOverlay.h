#pragma once

namespace Allocators
{
    class IAllocatorOverlay
    {
        public:
            IAllocatorOverlay() = default;
            ~IAllocatorOverlay() = default;

            virtual void RenderOverlay() = 0;
    };
} // namespace Allocators