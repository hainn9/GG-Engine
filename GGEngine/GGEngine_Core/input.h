#ifndef INPUT_H
#define INPUT_H

#include "core.h"

namespace GGEngine {

// Input Interface
class GGE_API Input
{
public:
    inline static bool IsKeyPressed(int keycode) { return s_InstanceInput->IsKeyPressedImpl(keycode); }
    inline static bool IsMousePressed(int button) { return s_InstanceInput->IsMousePressedImpl(button); }

    inline static float GetMousePosX() { return s_InstanceInput->GetMousePosXImpl(); }
    inline static float GetMousePosY() { return s_InstanceInput->GetMousePosYImpl(); }
protected:
    virtual bool IsKeyPressedImpl(int keycode) = 0;
    virtual bool IsMousePressedImpl(int button) = 0;

    virtual float GetMousePosXImpl() = 0;
    virtual float GetMousePosYImpl() = 0;
private:
    static Input* s_InstanceInput;
};

}

#endif // INPUT_H
