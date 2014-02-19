
#include "GuiRuntime.h"

namespace StiGame
{

GuiRuntime::GuiRuntime(void)
{
	style = new GuiStyle();
}


GuiRuntime::~GuiRuntime(void)
{
}

GuiStyle *GuiRuntime::getStyle(void)
{
	return style;
}



GuiRuntime *GuiRuntime::_instance = NULL;

}
