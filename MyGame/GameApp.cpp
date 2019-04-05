#include "ggengine.h"

class GameApp : public GGEngine::Application
{
public:
    GameApp() {}
    ~GameApp() {}
};

GGEngine::Application* GGEngine::CreateApplication()
{
    return new GameApp();
}
