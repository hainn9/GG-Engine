#include "layerstack.h"
#include <algorithm>

namespace GGEngine {

LayerStack::LayerStack()
{

}

LayerStack::~LayerStack()
{
    for(auto layer : m_Layers)
        delete layer;
}

void LayerStack::PushLayer(Layer *layer)
{
    m_Layers.emplace(m_Layers.begin()+m_InsertIndex, layer);
    m_InsertIndex++;
}

void LayerStack::PushLayerOverlay(Layer *overlay)
{
    m_Layers.emplace_back(overlay);
}

void LayerStack::PopLayer(Layer *layer)
{
    auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
    if(it != m_Layers.end())
    {
        m_Layers.erase(it);
        m_InsertIndex--;
    }
}

void LayerStack::PopLayerOverlay(Layer *overlay)
{
    auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
    if(it != m_Layers.end())
    {
        m_Layers.erase(it);
    }
}

}
