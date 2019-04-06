#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <functional>
#include "GGEngine_Core/core.h"
namespace GGEngine {

    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory {
        None = 0,
        EventCategoryApplication    = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4)
    };

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; } \
    virtual EventType GetEventType() const override { return GetStaticType(); } \
    virtual const char* GetName() const override { return #type; }

#define EVENT_CATEGORY(category) virtual int GetEventCategory() const override { return category; }

    class GGE_API Event {
    public:
        bool bHandle = false;
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetEventCategory() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category) { return GetEventCategory()&category; }
    };

    class EventDispatcher {
        template<typename T>
        using EventFunc = std::function<bool(T&)>;
    public:
        EventDispatcher(Event& event)
            :m_Event(event) {}

        template<typename T>
        bool Dispatch(EventFunc<T> func) {
            if(m_Event.GetEventType() == T::GetStaticType()) {
                m_Event.bHandle = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }

    private:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& s, const Event& e)
    {
        return s << e.ToString();
    }

}

#endif // EVENT_H
