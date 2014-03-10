#ifndef MOUSEEVENTLISTENER_H
#define MOUSEEVENTLISTENER_H

#include "MouseButtonEvent.h"

namespace StiGame
{

class MouseEventThrower;

class MouseEventListener
{
public:
	MouseEventListener();
	virtual ~MouseEventListener();
	virtual void handleEvent(MouseEventThrower *src, MouseButtonEvent *args);
};

}


#endif