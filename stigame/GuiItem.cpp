
#include "GuiItem.h"
#include "SDL.h"
#include <string>
#include "SColor.h"
#include "GuiRuntime.h"

namespace StiGame
{

GuiItem::GuiItem(void)
{
	style = GuiRuntime::getInstance()->getStyle();
	name = "GuiItem";
	init();
}

GuiItem::GuiItem(std::string iname)
{
	style = GuiRuntime::getInstance()->getStyle();
	name = iname;
	init();
}


GuiItem::~GuiItem(void)
{

}

void GuiItem::init(void)
{
	mouseOver = false;
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	background = style->getBackground();
	foreground = style->getForeground();
}

Surface *GuiItem::render(void)
{
	Surface *buffer = new Surface(width, height);
	buffer->fill(background);

	return buffer;
}

void GuiItem::onClick(Point *relp)
{

}

void GuiItem::onMouseMotion(Point *relp)
{

}

void GuiItem::clear(void)
{
	//clear your buffer here !
}

GuiStyle *GuiItem::getStyle(void)
{
	return style;
}

std::string GuiItem::getName(void)
{
	return name;
}

void GuiItem::setBackground(SColor *c)
{
	background = c;
}

SColor *GuiItem::getBackground(void)
{
	return background;
}

void GuiItem::setForeground(SColor *c)
{
	foreground = c;
}

SColor *GuiItem::getForeground(void)
{
	return foreground;
}

void GuiItem::setMouseOver(bool m_over)
{
	mouseOver = m_over;
}

bool GuiItem::getMouseOver(void)
{
	return mouseOver;
}

}
