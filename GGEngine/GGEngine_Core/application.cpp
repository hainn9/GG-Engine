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
        for(auto layer : m_LayerStack)
            layer->OnUpdate();

        m_Window->OnUpdate();
    }
}

void Application::PushLayer(Layer *layer)
{
    m_LayerStack.PushLayer(layer);
    layer->OnAttach();
}

void Application::PushLayerOverlay(Layer *overlay)
{
    m_LayerStack.PushLayerOverlay(overlay);
    overlay->OnAttach();
}

void Application::OnEvent(Event &e)
{
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

    for(auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
    {
        (*--it)->OnEvent(e);
        if(e.bHandle)
            break;
    }
}

bool Application::OnWindowClose(WindowCloseEvent &e)
{
    GGE_CORE_INFO("{0} ", e);
    m_Running = false;
    return true;
}

}
