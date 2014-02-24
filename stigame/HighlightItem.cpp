#include "HighlightItem.h"

namespace StiGame {

namespace Gui
{

HighlightItem::HighlightItem() : Item()
{
    //ctor
    highlightForeground = style->getHighlightForeground();
    highlightBackground = style->getHighlightBackground();
}

HighlightItem::HighlightItem(std::string i_name) : Item(i_name)
{
    highlightForeground = style->getHighlightForeground();
    highlightBackground = style->getHighlightBackground();
}


void HighlightItem::setHighlightBackground(SColor *color)
{
    highlightBackground = color;
}

void HighlightItem::setHighlightForeground(SColor *color)
{
    highlightForeground = color;
}

SColor *HighlightItem::getHighlightBackground(void)
{
    return highlightBackground;
}

SColor *HighlightItem::getHighlightForeground(void)
{
    return highlightForeground;
}

HighlightItem::~HighlightItem()
{
    //dtor
}

}

}
