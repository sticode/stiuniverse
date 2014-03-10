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

Uint8 MouseButtonEvent::GetSDLButton(MouseButton mbutton)
{
	if(mbutton == MB_LEFT)
	{
		return SDL_BUTTON_LEFT;
	}
	else if(mbutton == MB_MIDDLE)
	{
		return SDL_BUTTON_MIDDLE;
	}
	else if(mbutton == MB_RIGHT)
	{
		return SDL_BUTTON_RIGHT;
	}
	else if(mbutton == MB_X1)
	{
		return SDL_BUTTON_X1;
	}
	else if(mbutton == MB_X2)
	{
		return SDL_BUTTON_X2;
	}
	
	return SDL_BUTTON_LEFT;
}

MouseButton MouseButtonEvent::GetMouseButtonFromSDL(Uint8 mbutton)
{
	if(mbutton == SDL_BUTTON_LEFT)
	{
		return MB_LEFT;
	}
	else if(mbutton == SDL_BUTTON_MIDDLE)
	{
		return MB_MIDDLE;
	}
	else if(mbutton == SDL_BUTTON_RIGHT)
	{
		return MB_RIGHT;
	}
	else if(mbutton == SDL_BUTTON_X1)
	{
		return MB_X1;
	}
	else if(mbutton == SDL_BUTTON_X2)
	{
		return MB_X2;
	}
	
	return MB_LEFT;
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

MouseButton MouseButtonEvent::getMouseButton(void)
{
	Uint8 button = sdlEvent->button.button;
	
	if(button == SDL_BUTTON_LEFT)
	{
		return MB_LEFT;
	}
	else if(button == SDL_BUTTON_MIDDLE)
	{
		return MB_MIDDLE;
	}
	else if(button == SDL_BUTTON_RIGHT)
	{
		return MB_RIGHT;
	}
	else if(button == SDL_BUTTON_X1)
	{
		return MB_X1;
	}
	else if(button == SDL_BUTTON_X2)
	{
		return MB_X2;
	}
	
	return MB_LEFT;
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
