#include "SelectionEventThrower.h"

namespace StiGame {

SelectionEventThrower::SelectionEventThrower()
{
    //ctor
}

SelectionEventThrower::~SelectionEventThrower()
{
    //dtor
}

void SelectionEventThrower::subscribe(SelectionEventListener *listener)
{
    selectionListeners.push_back(listener);
}

void SelectionEventThrower::remove(SelectionEventListener *listener)
{
    selectionListeners.remove(listener);
}

void SelectionEventThrower::publish(SelectionEventThrower *src, SelectionEventArgs *args)
{
    std::list<SelectionEventListener*>::iterator lit(selectionListeners.begin()), lend(selectionListeners.end());
    for(; lit!=lend; ++lit)
    {
        (*lit)->handleEvent(src, args);
    }
}

}
