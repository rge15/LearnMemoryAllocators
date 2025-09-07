#include <iostream>
#include "GraphicsLayer.h"
#include "ImGuiApp.h"
#include <GLFW/glfw3.h>

int main()
{
    std::unique_ptr<Graphics::GraphicsLayer> graphicsLayer = std::make_unique<Graphics::GraphicsLayer>();
    Graphics::GraphicsContext& graphicsContext = graphicsLayer->GetContext();
    
    Graphics::ImGuiApp imGuiApp(graphicsContext); 

    while (!graphicsContext.ShouldCloseTheWindow()) {
        glfwPollEvents();

        graphicsLayer->SetNewFrame();

        imGuiApp.Render();

        graphicsLayer->Render();
    }

    return 0;
}