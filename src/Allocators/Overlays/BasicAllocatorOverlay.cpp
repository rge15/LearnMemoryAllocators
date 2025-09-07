#include "BasicAllocatorOverlay.h"
#include "BasicAllocator.h"

namespace Allocators
{
    BasicAllocatorOverlay::BasicAllocatorOverlay()
        : m_Allocator{ std::make_unique<BasicAllocator<int>>() }
    {
    }

    void BasicAllocatorOverlay::RenderOverlay()
    {
        DrawAllocatorData();
        DrawContainersData();
        DrawContainersOperations();
    }

    void BasicAllocatorOverlay::DrawAllocatorData() const
    {
        if(ImGui::CollapsingHeader("AllocatorInfo"))
        {

        }
    }

    void BasicAllocatorOverlay::DrawContainersData() const
    {
        if(ImGui::CollapsingHeader("ConatinersInfo"))
        {

        }
    }

    void BasicAllocatorOverlay::DrawContainersOperations()
    {
        if(ImGui::CollapsingHeader("ConatinersOperations"))
        {

        }
    }

} // namespace Allocators