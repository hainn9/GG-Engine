#include "ggengine.h"

class ExampleLayer : public GGEngine::Layer
{
public:
    ExampleLayer()
        :Layer("Example") {}

    void OnUpdate() override
    {
        if(GGEngine::Input::IsKeyPressed(GGE_KEY_TAB))
            GGE_TRACE("Tab key is pressed!");
    }

    void OnImGuiRender() override
    {
        ImGui::Begin("Test");
        ImGui::Text("Hello World");
        ImGui::End();
    }

    void OnEvent(GGEngine::Event& e) override
    {
        if(e.GetEventType() == GGEngine::EventType::KeyPressed)
        {
            GGEngine::KeyPressedEvent& event = (GGEngine::KeyPressedEvent&)e;
            GGE_TRACE("Key {0} is pressed", (char)event.GetKey());
        }
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
