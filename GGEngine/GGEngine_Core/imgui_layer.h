#ifndef IMGUI_LAYER_H
#define IMGUI_LAYER_H

#include "layer.h"
namespace GGEngine {

class GGE_API ImGui_Layer : public Layer
{
public:
    ImGui_Layer();
    ~ImGui_Layer();

    void OnAttach() override;
    void OnDetach() override;
    void OnImGuiRender() override;
    void OnEvent(Event&) override;

    void Begin();
    void End();
};

}

#endif // IMGUI_LAYER_H
