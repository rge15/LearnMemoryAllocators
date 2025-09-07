#include "ImGuiAllocatorHandler.h"

namespace Allocators
{

    void ImGuiAllocatorHandler::AddLogMessage(std::string p_Msg)
    {
        m_AllocatorLog.push(p_Msg);
    }

}// namespace Allocators
