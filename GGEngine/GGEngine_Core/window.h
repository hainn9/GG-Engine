#ifndef WINDOW_H
#define WINDOW_H

#include "core.h"
#include "Event/event.h"
#include <functional>
namespace GGEngine {

struct WindowProps
{
    std::string Title;
    unsigned int Width;
    unsigned int Height;
    WindowProps(const std::string& title = "Engine Window", unsigned int width = 1280, unsigned int height = 720)
        :Title(title), Width(width), Height(height) {}
};

class GGE_API Window {
public:
    using EventCallbackFn = std::function<void(Event&)>;

    virtual ~Window() {}

    virtual void OnUpdate() = 0;
    virtual unsigned int GetWidth() const = 0;
    virtual unsigned int GetHeight() const = 0;

    virtual void SetEventCallbackFn(const EventCallbackFn& callback) = 0;
    virtual void SetVSync(bool enable) = 0;
    virtual bool IsVSync() const = 0;

    static Window* CreateWindow(const WindowProps& props = WindowProps());
};

}

#endif // WINDOW_H
