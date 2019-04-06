#include "application.h"
#include "Event/mouseevent.h"
#include "log.h"

namespace GGEngine {

Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
    MouseMovedEvent e(800,600);
    GGE_TRACE(e);
    while(true);
}

}
