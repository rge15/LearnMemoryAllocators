#pragma once
#include <memory>

struct GLFWwindow;

namespace Graphics
{
    struct GraphicsContext
    {
        bool ShouldCloseTheWindow() const;
        GLFWwindow* m_Window {nullptr};
    };

    class GraphicsLayer
    {
        public:
            GraphicsLayer();
            ~GraphicsLayer();

            void SetNewFrame() const;

            void Render() const;

            GraphicsContext& GetContext() const { return *m_Context; }

            void Init();

        private:

            std::unique_ptr<GraphicsContext> m_Context;
    };
    
} // namespace Graphics