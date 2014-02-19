#include <iostream>
#include "GuiStyle.h"

#include "GamePath.h"

namespace StiGame
{

GuiStyle::GuiStyle(void)
{
	foreground = SColor(200, 250, 250);
	background = SColor(15, 15, 15);
	highlightForeground = SColor(255, 255, 255);
	highlightBackground = SColor(120, 120, 120);

	normalFont = new SFont(GamePath::getFilepath(AssetRoot, "font.ttf").c_str(), 14);
	dropListArrow = new Surface(GamePath::getFilepath(AssetGui, "droplist_arrow.png").c_str());
	upArrow = new Surface(GamePath::getFilepath(AssetGui, "uparrow.png").c_str());
	downArrow = new Surface(GamePath::getFilepath(AssetGui, "downarrow.png").c_str());
	checkbox = new Surface(GamePath::getFilepath(AssetGui, "checkbox.png").c_str());
	checkboxChecked = new Surface(GamePath::getFilepath(AssetGui, "checkbox_checked.png").c_str());
	radio = new Surface(GamePath::getFilepath(AssetGui, "radio.png").c_str());
	radioChecked = new Surface(GamePath::getFilepath(AssetGui, "radio_true.png").c_str());
}

Surface *GuiStyle::getRadio(void)
{
    return radio;
}

Surface *GuiStyle::getRadioChecked(void)
{
    return radioChecked;
}

Surface *GuiStyle::getCheckbox(void)
{
    return checkbox;
}

Surface *GuiStyle::getCheckboxChecked(void)
{
    return checkboxChecked;
}

Surface *GuiStyle::getDropListArrow(void)
{
    return dropListArrow;
}

SColor *GuiStyle::getBackground(void)
{
	return &background;
}

SColor *GuiStyle::getForeground(void)
{
	return &foreground;
}

SColor *GuiStyle::getHighlightBackground(void)
{
	return &highlightBackground;
}

SColor *GuiStyle::getHighlightForeground(void)
{
	return &highlightForeground;
}

SFont *GuiStyle::getNormalFont(void)
{
	return normalFont;
}

Surface *GuiStyle::getUpArrow(void)
{
    return upArrow;
}

Surface *GuiStyle::getDownArrow(void)
{
    return downArrow;
}

void GuiStyle::unload(void)
{
	delete normalFont;
}

GuiStyle::~GuiStyle(void)
{
}
}
