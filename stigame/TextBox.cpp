#include "TextBox.h"

namespace StiGame
{

namespace Gui
{

TextBox::TextBox()
	: HighlightItem("TextBox")
{
	text = "";
	stringBuffer = 0;
	font = style->getNormalFont();
	focus = false;
}

TextBox::~TextBox()
{
	if(stringBuffer != 0)
	{
		delete stringBuffer;
	}
}

SFont* TextBox::getFont(void)
{
	return font;
}

void TextBox::setFont(SFont *m_font)
{
	font = m_font;
}

std::string TextBox::getText(void)
{
	return text;
}

void TextBox::setText(std::string m_text)
{
	text = m_text;
	renderString();
}

void TextBox::onClick(Point *relpt)
{

}

bool TextBox::isFocus(void)
{
	return focus;
}

void TextBox::setFocus(bool m_focus)
{
	focus = m_focus;
}

Surface* TextBox::render(void)
{
	Surface *buffer = new Surface(width, height);
	
	buffer->fill(background);
	
	return buffer;
}

void TextBox::renderString(void)
{
	if(stringBuffer != 0)
	{
		delete stringBuffer;
	}
	
	stringBuffer = font->renderText(text, foreground);
}

}

}