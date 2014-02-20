#include "GuiHighlightItem.h"

namespace StiGame {

namespace Gui
{

GuiHighlightItem::GuiHighlightItem() : GuiItem()
{
    //ctor
    highlightForeground = style->getHighlightForeground();
    highlightBackground = style->getHighlightBackground();
}


void GuiHighlightItem::setHighlightBackground(SColor *color)
{
    highlightBackground = color;
}

void GuiHighlightItem::setHighlightForeground(SColor *color)
{
    highlightForeground = color;
}

SColor *GuiHighlightItem::getHighlightBackground(void)
{
    return highlightBackground;
}

SColor *GuiHighlightItem::getHighlightForeground(void)
{
    return highlightForeground;
}

GuiHighlightItem::~GuiHighlightItem()
{
    //dtor
}

}

}
