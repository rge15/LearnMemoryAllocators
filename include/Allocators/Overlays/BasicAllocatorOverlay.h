#pragma once
#include "CommonAllocatorOverlay.h"
#include "BasicAllocator.h"
#include <memory>
#include <vector>


namespace Allocators
{
    class BasicAllocatorOverlay : public CommonAllocatorOverlay
    {
        using AllocatorType = BasicAllocator<int>;
        using ContainerType = std::vector<int,AllocatorType>;

        public:
            BasicAllocatorOverlay();

            void RenderOverlay() override;

        private:
            void DrawAllocatorData() const;

            void DrawContainersData() const;

            void DrawContainersOperations();

            std::unique_ptr<AllocatorType> m_Allocator;
            std::vector<ContainerType> m_Containers;
    };
}