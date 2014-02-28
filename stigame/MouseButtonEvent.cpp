#include "MouseButtonEvent.h"
namespace StiGame
{

MouseButtonEvent::MouseButtonEvent()
    : EventArgs()
{
    //ctor
}

MouseButtonEvent::MouseButtonEvent(SDL_Event *m_sdlEvent)
    : EventArgs(m_sdlEvent)
{

}

Sint32 MouseButtonEvent::getX(void)
{
    return sdlEvent->button.x;
}

Sint32 MouseButtonEvent::getY(void)
{
    return sdlEvent->button.y;
}

Uint8 MouseButtonEvent::getButton(void)
{
    return sdlEvent->button.button;
}
Uint32 MouseButtonEvent::getWindowID(void)
{
    return sdlEvent->button.windowID;
}

bool MouseButtonEvent::isDown(void)
{
    return (sdlEvent->button.state == SDL_PRESSED);
}

MouseButtonEvent::~MouseButtonEvent()
{
    //dtor
}

}
