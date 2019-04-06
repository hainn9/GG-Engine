#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H

#include "window.h"
#include "GLFW/glfw3.h"

namespace GGEngine {

class OpenGL_Window : public Window
{
public:
    OpenGL_Window(const WindowProps& props);
    virtual ~OpenGL_Window();

    void OnUpdate() override;
    inline unsigned int GetWidth() const override { return m_Data.Width; }
    unsigned int GetHeight() const override { return m_Data.Height; }

    void SetEventCallbackFn(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
    void SetVSync(bool enable) override;
    bool IsVSync() const override { return m_Data.VSync; }

private:
    virtual void Init(const WindowProps& props);
    virtual void Shutdown();

private:
    GLFWwindow* m_Window;
    struct WindowData
    {
        std::string Title;
        unsigned int Width, Height;
        bool VSync;

        EventCallbackFn EventCallback;
    };

    WindowData m_Data;

};

}

#endif // OPENGL_WINDOW_H
