#include "ggengine.h"

class ExampleLayer : public GGEngine::Layer
{
public:
    ExampleLayer()
        :Layer("Example") {}

    void OnUpdate() override
    {
//        GGE_INFO("Example Layer");
    }

    void OnImGuiRender() override
    {
        ImGui::Begin("Test");
        ImGui::Text("Hello World");
        ImGui::End();
    }

    void OnEvent(GGEngine::Event& e) override
    {
        GGE_TRACE("{0} ", e);
    }
};

class GameApp : public GGEngine::Application
{
public:
    GameApp()
    {
        PushLayer(new ExampleLayer());
    }
    ~GameApp() {}
};

GGEngine::Application* GGEngine::CreateApplication()
{
    return new GameApp();
}
