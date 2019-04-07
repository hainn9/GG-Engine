#ifndef APPLICATION_H
#define APPLICATION_H

#include "core.h"
#include "Event/event.h"
#include "Event/applicationevent.h"
#include "Event/mouseevent.h"
#include "Event/keyevent.h"
#include "window.h"
#include "layerstack.h"
#include "imgui_layer.h"
#include <memory>
#include <functional>

namespace GGEngine {

    class GGE_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void PushLayer(Layer* layer);
        void PushLayerOverlay(Layer* overlay);

        void OnEvent(Event& e);

        inline static Application& Get() { return *s_Instance; }

        inline Window& GetWindow() { return *m_Window; }

    private:
        bool OnWindowClose(WindowCloseEvent& e);
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        ImGui_Layer* m_ImGuiLayer;
        LayerStack m_LayerStack;
        static Application* s_Instance;
    };

    Application* CreateApplication();
}

#endif // APPLICATION_H
