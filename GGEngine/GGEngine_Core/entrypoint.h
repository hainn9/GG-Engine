#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

extern GGEngine::Application* GGEngine::CreateApplication();

int main(/*int argc, char** argv*/)
{
    GGEngine::Log::Init();

    auto app = GGEngine::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif // ENTRYPOINT_H
