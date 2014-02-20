
#include "GuiRuntime.h"

namespace StiGame
{

GuiRuntime::GuiRuntime(void)
{
	style = new Gui::Style();
}


GuiRuntime::~GuiRuntime(void)
{
}

Gui::Style *GuiRuntime::getStyle(void)
{
	return style;
}



GuiRuntime *GuiRuntime::_instance = NULL;

}
