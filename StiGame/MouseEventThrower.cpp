#include "MouseEventThrower.h"

namespace StiGame
{

MouseEventThrower::MouseEventThrower()
{

}

MouseEventThrower::~MouseEventThrower()
{

}
	
void MouseEventThrower::subscribe(MouseEventListener *listener)
{
	mouseListeners.push_back(listener);

}

void MouseEventThrower::remove(MouseEventListener *listener)
{
	mouseListeners.remove(listener);
}

//std::list<MouseEventListener*> mouseListeners;
	
void MouseEventThrower::publish(MouseEventThrower *source, MouseButtonEvent *args)
{
	std::list<MouseEventListener*>::iterator lit(mouseListeners.begin()), lend(mouseListeners.end());
	for(;lit!=lend;++lit)
	{
		(*lit)->handleEvent(source, args);
	}
}

}