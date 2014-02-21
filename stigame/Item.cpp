
#include "Item.h"
#include "SDL.h"
#include <string>
#include "SColor.h"
#include "Runtime.h"

namespace StiGame
{

namespace Gui
{

Item::Item(void)
{
	style = Runtime::getInstance()->getStyle();
	name = "GuiItem";
	init();
}

Item::Item(std::string iname)
{
	style = Runtime::getInstance()->getStyle();
	name = iname;
	init();
}


Item::~Item(void)
{

}

void Item::init(void)
{
	mouseOver = false;
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	background = style->getBackground();
	foreground = style->getForeground();
}

Surface *Item::render(void)
{
	Surface *buffer = new Surface(width, height);
	buffer->fill(background);

	return buffer;
}

void Item::onClick(Point *relp)
{

}

void Item::onMouseMotion(Point *relp)
{

}

void Item::clear(void)
{
	//clear your buffer here !
}

Style *Item::getStyle(void)
{
	return style;
}

std::string Item::getName(void)
{
	return name;
}

void Item::setBackground(SColor *c)
{
	background = c;
}

SColor *Item::getBackground(void)
{
	return background;
}

void Item::setForeground(SColor *c)
{
	foreground = c;
}

SColor *Item::getForeground(void)
{
	return foreground;
}

void Item::setMouseOver(bool m_over)
{
	mouseOver = m_over;
}

bool Item::getMouseOver(void)
{
	return mouseOver;
}

}

}
