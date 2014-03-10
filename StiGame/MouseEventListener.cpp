#include "MouseEventListener.h"
#include "MouseEventThrower.h"

namespace StiGame
{
MouseEventListener::MouseEventListener()
{


}

MouseEventListener::~MouseEventListener()
{

}

void MouseEventListener::handleEvent(MouseEventThrower *src, MouseButtonEvent *args)
{
	//to override
}

}