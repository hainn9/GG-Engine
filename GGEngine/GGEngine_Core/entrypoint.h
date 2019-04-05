#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

extern GGEngine::Application* GGEngine::CreateApplication();

int main(/*int argc, char** argv*/)
{
    auto app = GGEngine::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif // ENTRYPOINT_H
