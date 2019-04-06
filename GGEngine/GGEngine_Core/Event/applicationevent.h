#ifndef APPLICATIONEVENT_H
#define APPLICATIONEVENT_H

#include "event.h"
#include <sstream>

namespace GGEngine {

class GGE_API WindowResizeEvent : public Event {
public:
    WindowResizeEvent(unsigned int width, unsigned int height)
        :m_Width(width), m_Height(height) {}

    inline unsigned int GetWidth() const { return m_Width; }
    inline unsigned int GetHeight() const { return m_Height; }

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "WindowResizeEvent: " << m_Width<<","<<m_Height;
        return ss.str();
    }

    EVENT_CLASS_TYPE(WindowResize)
    EVENT_CATEGORY(EventCategoryApplication)

private:
    unsigned int m_Width, m_Height;
};

class GGE_API WindowCloseEvent : public Event {
public:
    WindowCloseEvent() {}

    EVENT_CLASS_TYPE(WindowClose)
    EVENT_CATEGORY(EventCategoryApplication)
};

class GGE_API WindowFocusEvent : public Event {
public:
    WindowFocusEvent() {}

    EVENT_CLASS_TYPE(WindowFocus)
    EVENT_CATEGORY(EventCategoryApplication)
};

class GGE_API WindowLostFocusEvent : public Event {
public:
    WindowLostFocusEvent() {}

    EVENT_CLASS_TYPE(WindowLostFocus)
    EVENT_CATEGORY(EventCategoryApplication)
};

class GGE_API WindowMovedEvent : public Event {
public:
    WindowMovedEvent() {}

    EVENT_CLASS_TYPE(WindowMoved)
    EVENT_CATEGORY(EventCategoryApplication)
};

class GGE_API AppTickEvent : public Event {
public:
    AppTickEvent() {}

    EVENT_CLASS_TYPE(AppTick)
    EVENT_CATEGORY(EventCategoryApplication)
};

class GGE_API AppUpdateEvent : public Event {
public:
    AppUpdateEvent() {}

    EVENT_CLASS_TYPE(AppUpdate)
    EVENT_CATEGORY(EventCategoryApplication)
};

class GGE_API AppRenderEvent : public Event {
public:
    AppRenderEvent() {}

    EVENT_CLASS_TYPE(AppRender)
    EVENT_CATEGORY(EventCategoryApplication)
};

}

#endif // APPLICATIONEVENT_H
