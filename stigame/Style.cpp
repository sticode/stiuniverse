#include <iostream>
#include "Style.h"

#include "GamePath.h"

namespace StiGame
{

namespace Gui
{

Style::Style(void)
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

Surface *Style::getRadio(void)
{
    return radio;
}

Surface *Style::getRadioChecked(void)
{
    return radioChecked;
}

Surface *Style::getCheckbox(void)
{
    return checkbox;
}

Surface *Style::getCheckboxChecked(void)
{
    return checkboxChecked;
}

Surface *Style::getDropListArrow(void)
{
    return dropListArrow;
}

SColor *Style::getBackground(void)
{
	return &background;
}

SColor *Style::getForeground(void)
{
	return &foreground;
}

SColor *Style::getHighlightBackground(void)
{
	return &highlightBackground;
}

SColor *Style::getHighlightForeground(void)
{
	return &highlightForeground;
}

SFont *Style::getNormalFont(void)
{
	return normalFont;
}

Surface *Style::getUpArrow(void)
{
    return upArrow;
}

Surface *Style::getDownArrow(void)
{
    return downArrow;
}

void Style::unload(void)
{
	delete normalFont;
}

Style::~Style(void)
{
}

}

}
