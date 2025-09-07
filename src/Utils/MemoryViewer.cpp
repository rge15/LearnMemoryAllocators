#include "MemoryViewer.h"
#include "imgui.h"

MemoryViewer::MemoryViewer()
    : m_visible { false }
{}

void MemoryViewer::Render()
{
    ImGui::Begin("Memory");
    ImGui::End();
}

INITIALIZE_SINGLETON(MemoryViewer)