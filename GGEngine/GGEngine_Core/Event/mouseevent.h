#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include "event.h"
#include <sstream>

namespace GGEngine {

class GGE_API MouseMovedEvent : public Event {
public:
    MouseMovedEvent(float posX, float posY)
        :m_PosX(posX), m_PosY(posY) {}

    inline float GetPosX() const { return m_PosX; }
    inline float GetPosY() const { return m_PosY; }

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "MouseMovedEvent: " << m_PosX << "," << m_PosY;
        return ss.str();
    }

    EVENT_CLASS_TYPE(MouseMoved)
    EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput)

private:
    float m_PosX, m_PosY;
};

class GGE_API MouseScrolledEvent : public Event {
public:
    MouseScrolledEvent(float offsetX, float offsetY)
        :m_OffsetX(offsetX),m_OffsetY(offsetY) {}

    inline float GetOffsetX() const { return m_OffsetX; }
    inline float GetOffsetY() const { return m_OffsetY; }

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "MouseScrolledEvent: " << m_OffsetX << "," << m_OffsetY;
        return ss.str();
    }

    EVENT_CLASS_TYPE(MouseScrolled)
    EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput)

private:
    float m_OffsetX, m_OffsetY;
};

class GGE_API MouseButtonEvent : public Event {
public:
    inline int GetMouseButton() const { return m_MouseButton; }
    EVENT_CATEGORY(EventCategoryMouseButton | EventCategoryInput)

protected:
    MouseButtonEvent(int button)
        :m_MouseButton(button) {}
    int m_MouseButton;
};

class GGE_API MouseButtonPressedEvent : public MouseButtonEvent {
public:
    MouseButtonPressedEvent(int button)
        :MouseButtonEvent(button) {}
    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "MouseButtonPressedEvent: " << GetMouseButton();
        return ss.str();
    }

    EVENT_CLASS_TYPE(MouseButtonPressed)
};

class GGE_API MouseButtonReleasedEvent : public MouseButtonEvent {
public:
    MouseButtonReleasedEvent(int button)
        :MouseButtonEvent(button) {}
    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "MouseButtonReleasedEvent: " << GetMouseButton();
        return ss.str();
    }

    EVENT_CLASS_TYPE(MouseButtonReleased)
};

}

#endif // MOUSEEVENT_H
