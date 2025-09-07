#include "GraphicsLayer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "Asserts.h"

namespace Graphics
{
    bool GraphicsContext::ShouldCloseTheWindow() const
    {
        return glfwWindowShouldClose(m_Window);
    }

    GraphicsLayer::GraphicsLayer()
    : m_Context { std::make_unique<GraphicsContext>() }
    {
        Init();
    }

    GraphicsLayer::~GraphicsLayer()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(m_Context->m_Window);
        glfwTerminate();
    }

    void GraphicsLayer::Init()
    {
        if (!glfwInit()) {
            ASSERT_MSG(false, "GLFW Failed when initializing" );
        }

        GLFWwindow* window = glfwCreateWindow(1280, 720, "Mi Aplicación con ImGui", NULL, NULL);
        
        if (!window) {
            glfwTerminate();
            ASSERT_MSG(window, "GLFW Failed when creating the window" );
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            ASSERT_MSG(false, "Glad Failed  loading OpenGl" );
        }

        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 130");

        m_Context->m_Window = window;
    }

    void GraphicsLayer::SetNewFrame() const
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void GraphicsLayer::Render() const
    {
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(m_Context->m_Window);
    }

} //namespace Graphics