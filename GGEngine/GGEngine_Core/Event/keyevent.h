#ifndef KEYEVENT_H
#define KEYEVENT_H

#include "event.h"
#include <sstream>

namespace GGEngine {

class GGE_API KeyEvent : public Event {
public:
    inline int GetKey() const { return m_KeyCode; }
    EVENT_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

protected:
    KeyEvent(int keycode)
        :m_KeyCode(keycode) {}
    int m_KeyCode;
};

class GGE_API KeyPressedEvent : public KeyEvent {
public:
    KeyPressedEvent(int keycode, int repeatCount)
        :KeyEvent(keycode), m_RepeatCount(repeatCount) {}

    inline int GetRepeatCount() const { return m_RepeatCount; }

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "KeyPressedEvent: " << GetKey();
        return ss.str();
    }

    EVENT_CLASS_TYPE(KeyPressed)

private:
    int m_RepeatCount;
};

class GGE_API KeyReleasedEvent : public KeyEvent {
public:
    KeyReleasedEvent(int keycode)
        :KeyEvent(keycode) {}

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "KeyReleasedEvent: " << GetKey();
        return ss.str();
    }

    EVENT_CLASS_TYPE(KeyReleased)
};

class GGE_API KeyTypedEvent : public KeyEvent {
public:
    KeyTypedEvent(int keycode)
        :KeyEvent(keycode) {}

    std::string ToString() const override
    {
        std::stringstream ss;
        ss << "KeyTypedEvent: " << GetKey();
        return ss.str();
    }

    EVENT_CLASS_TYPE(KeyTyped)
};

}

#endif // KEYEVENT_H
