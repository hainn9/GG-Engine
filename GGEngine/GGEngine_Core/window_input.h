#ifndef WINDOW_INPUT_H
#define WINDOW_INPUT_H

#include "input.h"

namespace GGEngine {

class Window_Input : public Input
{
protected:
    virtual bool IsKeyPressedImpl(int keycode) override;
    virtual bool IsMousePressedImpl(int button) override;

    virtual float GetMousePosXImpl() override;
    virtual float GetMousePosYImpl() override;
};

}

#endif // WINDOW_INPUT_H
