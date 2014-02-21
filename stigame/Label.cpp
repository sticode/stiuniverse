
#include "Label.h"

namespace StiGame
{

namespace Gui
{

Label::Label(void)  : Item("Label")
{
	caption = "";
	font = style->getNormalFont();
	transparent = true;
	stringBuffer = 0;
}



Label::~Label(void)
{
}

void Label::setCaption(char* m_caption)
{
	caption = m_caption;
	renderCaption();
}

char* Label::getCaption(void)
{
	return caption;
}

void Label::setFont(SFont *m_font)
{
	font = m_font;
}

void Label::renderCaption(void)
{
	if(stringBuffer != 0)
	{
		delete stringBuffer;
	}

	stringBuffer = font->renderText(caption, foreground);
}

void Label::autosize(void)
{
	if(stringBuffer == 0)
	{
		renderCaption();
	}

	width = stringBuffer->getWidth();
	height = stringBuffer->getHeight();
}

void Label::setTransparent(bool m_transparent)
{
	transparent = m_transparent;
}

bool Label::getTransparent(void)
{
	return transparent;
}

Surface *Label::render(void)
{
	if(isEmpty())
	{
		autosize();
	}

	if(stringBuffer == 0)
	{
		renderCaption();
	}

	Surface *buffer = new Surface(width,height);

	if(!transparent)
	{
		buffer->fill(background);
	}
	else
	{
		buffer->makeTransparent();
	}

	SDL_Rect *src = stringBuffer->getRect();
	SDL_Rect *dst = new SDL_Rect();

	dst->x = (width / 2) - (src->w / 2);
	dst->y = (height / 2) - (src->h / 2);
	dst->w = src->w;
	dst->h = src->h;

	buffer->blit(stringBuffer, src, dst);

	delete dst;
	delete src;

	return buffer;
}

}

}
