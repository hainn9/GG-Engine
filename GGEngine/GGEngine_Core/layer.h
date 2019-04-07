#ifndef LAYER_H
#define LAYER_H

#include "core.h"
#include "Event/event.h"

namespace GGEngine {

class GGE_API Layer
{
public:
    Layer(const std::string& name = "Layer")
        :m_LayerName(name) {}

    virtual ~Layer() {}

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate() {}

    virtual void OnEvent(Event&) {}

    inline const std::string& GetLayerName() const { return m_LayerName; }

protected:
    std::string m_LayerName;
};

}

#endif // LAYER_H
