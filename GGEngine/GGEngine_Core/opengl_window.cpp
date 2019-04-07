#include "opengl_window.h"
#include "log.h"
#include "Event/applicationevent.h"
#include "Event/mouseevent.h"
#include "Event/keyevent.h"

namespace GGEngine {
static bool s_GLFWInitialized = false;

static void GLFWErrorCallback(int error, const char* desciption)
{
    GGE_CORE_ERROR("GLFW Error {0} : {1}", error, desciption);
}

Window* Window::CreateWindow(const WindowProps &props)
{
    return new OpenGL_Window(props);
}

OpenGL_Window::OpenGL_Window(const WindowProps &props)
{
    Init(props);
}

OpenGL_Window::~OpenGL_Window()
{
    Shutdown();
}

void OpenGL_Window::OnUpdate()
{
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
}

void OpenGL_Window::SetVSync(bool enable)
{
    if(enable)
        glfwSwapInterval(1);
    else
        glfwSwapInterval(0);
    m_Data.VSync = enable;
}

void OpenGL_Window::Init(const WindowProps &props)
{
    m_Data.Title = props.Title;
    m_Data.Width = props.Width;
    m_Data.Height = props.Height;

    GGE_CORE_INFO("Create window: {0} {1}, {2}", props.Title, props.Width, props.Height);
    if(!s_GLFWInitialized)
    {
        int status = glfwInit();
        if(!status)
            GGE_CORE_ERROR("Could not initialize GLFW!");
        glfwSetErrorCallback(GLFWErrorCallback);
        s_GLFWInitialized = true;
    }
    // Set all the required options for GLFW
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );

    m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(m_Window);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    if(!status)
        GGE_CORE_ERROR("Could not initialize GLAD!");

    glfwSetWindowUserPointer(m_Window, &m_Data);
    SetVSync(true);

    // Set GLFW callback
    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height){
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        data.Width = width;
        data.Height = height;

        WindowResizeEvent event(width, height);
        data.EventCallback(event);
    });

    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window){
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        WindowCloseEvent event;
        data.EventCallback(event);
    });

    glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double offsetX, double offsetY){
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        MouseScrolledEvent event((float)offsetX, (float)offsetY);
        data.EventCallback(event);
    });

    glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        switch (action) {
            case GLFW_PRESS:
            {
                KeyPressedEvent event(key, 0);
                data.EventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                KeyReleasedEvent event(key);
                data.EventCallback(event);
                break;
            }
            case GLFW_REPEAT:
            {
                KeyPressedEvent event(key, 1);
                data.EventCallback(event);
                break;
            }
        }

        (void)scancode;
        (void)mods;
    });

    glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods){
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        switch (action) {
            case GLFW_PRESS:
            {
                MouseButtonPressedEvent event(button);
                data.EventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                MouseButtonReleasedEvent event(button);
                data.EventCallback(event);
                break;
            }
        }

        (void)mods;
    });

    glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double posX, double posY){
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        MouseMovedEvent event((float)posX, (float)posY);
        data.EventCallback(event);
    });
}

void OpenGL_Window::Shutdown()
{
    glfwDestroyWindow(m_Window);
}

}
