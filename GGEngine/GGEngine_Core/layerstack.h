#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include "core.h"
#include "layer.h"
#include <vector>

namespace GGEngine {

class GGE_API LayerStack
{
public:
    LayerStack();
    ~LayerStack();

    void PushLayer(Layer* layer);
    void PushLayerOverlay(Layer* overlay);

    void PopLayer(Layer* layer);
    void PopLayerOverlay(Layer* overlay);

    inline std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
    inline std::vector<Layer*>::iterator end() { return m_Layers.end(); }
private:
    std::vector<Layer*> m_Layers;
    unsigned int m_InsertIndex;
};

}

#endif // LAYERSTACK_H
