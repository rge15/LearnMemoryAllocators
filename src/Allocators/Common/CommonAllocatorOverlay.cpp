#include "CommonAllocatorOverlay.h"
#include "Asserts.h"
#include <typeinfo>
#include <cxxabi.h>

namespace Allocators
{
    void CommonAllocatorOverlay::RenderOverlay()
    {
        ASSERT_MSG(false, "Trying to render a overlay without a valid `RenderOverlay()` method definition, or calling this directly from a CommonAllocatorOverlay.");
    }
            
    void CommonAllocatorOverlay::RenderCommonOverlay()
    {
        std::string const overlayName = typeid(*this).name();
        char const * const demangledOverlayName = abi::__cxa_demangle(overlayName.c_str(),nullptr,nullptr,nullptr);
        ImGui::Begin(demangledOverlayName);
        CommonOverlayDataRender();
        RenderOverlay();
        ImGui::End();
    }

    void CommonAllocatorOverlay::CommonOverlayDataRender()
    {
        ImGui::Text("Common Data");
        ImGui::NewLine();
    }

}