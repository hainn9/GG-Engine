#ifndef APPLICATION_H
#define APPLICATION_H

#include "core.h"

namespace GGEngine {

    class GGE_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    Application* CreateApplication();
}

#endif // APPLICATION_H
