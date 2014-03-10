#ifndef MOUEEEVENTTHROWER_H
#define MOUSEEVENTTHROWER_H

#include "MouseEventListener.h"
#include <list>

namespace StiGame
{


class MouseEventThrower
{
public:
	MouseEventThrower();
	virtual ~MouseEventThrower();
	
	virtual void subscribe(MouseEventListener *listener);
	virtual void remove(MouseEventListener *listener);
protected:
	std::list<MouseEventListener*> mouseListeners;
	
	virtual void publish(MouseEventThrower *source, MouseButtonEvent *args);

};

}


#endif