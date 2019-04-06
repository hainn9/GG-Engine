#ifndef APPLICATION_H
#define APPLICATION_H

#include "core.h"
#include "Event/event.h"
#include "Event/applicationevent.h"
#include "Event/mouseevent.h"
#include "Event/keyevent.h"
#include "window.h"
#include <memory>
#include <functional>

namespace GGEngine {

    class GGE_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

    private:
        bool OnWindowClose(WindowCloseEvent& e);
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    Application* CreateApplication();
}

#endif // APPLICATION_H
