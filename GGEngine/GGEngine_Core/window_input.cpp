#include "window_input.h"
#include "application.h"
#include "GLFW/glfw3.h"

namespace GGEngine {
Input* Input::s_InstanceInput = new Window_Input();

bool Window_Input::IsKeyPressedImpl(int keycode)
{
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetKey(window, keycode);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool Window_Input::IsMousePressedImpl(int button)
{
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetMouseButton(window, button);
    return state == GLFW_PRESS;
}

float Window_Input::GetMousePosXImpl()
{
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    double posX, posY;
    glfwGetCursorPos(window, &posX, &posY);
    return (float)posX;
}

float Window_Input::GetMousePosYImpl()
{
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    double posX, posY;
    glfwGetCursorPos(window, &posX, &posY);
    return (float)posY;
}

}
