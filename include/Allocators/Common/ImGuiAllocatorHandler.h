#pragma once
#include <format>
#include <queue>
#include <string>

namespace Allocators
{
    class ImGuiAllocatorHandler
    {
        public:
            ImGuiAllocatorHandler() = default;

            std::queue<std::string> & GetAllocatorMessages() { return m_AllocatorLog; };
        
        protected:
            void AddLogMessage( std::string p_LogMsg );

        private:
            std::queue<std::string> m_AllocatorLog;
    };
}// namespace Allocators