#include "SelectionEventArgs.h"

namespace StiGame
{

namespace Gui
{

SelectionEventArgs::SelectionEventArgs(ValueObject *m_selection)
{
    //ctor
    selection = m_selection;
}

SelectionEventArgs::~SelectionEventArgs()
{
    //dtor
}

ValueObject *SelectionEventArgs::getSelection(void)
{
    return selection;
}

}

}
