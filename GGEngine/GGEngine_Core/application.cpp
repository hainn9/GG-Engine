#include "application.h"
#include "log.h"
#include "GLFW/glfw3.h"

namespace GGEngine {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

Application::Application()
{
    m_Window = std::unique_ptr<Window>(Window::CreateWindow());
    m_Window->SetEventCallbackFn(BIND_EVENT_FN(OnEvent));
}

Application::~Application()
{

}

void Application::Run()
{
    while(m_Running)
    {
        glClearColor(0.3f, 0.2f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        m_Window->OnUpdate();
    }
}

void Application::OnEvent(Event &e)
{
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
}

bool Application::OnWindowClose(WindowCloseEvent &e)
{
    GGE_CORE_INFO("{0} ", e);
    m_Running = false;
    return true;
}

}
