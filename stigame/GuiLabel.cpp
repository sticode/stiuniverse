
#include "GuiLabel.h"

namespace StiGame
{

GuiLabel::GuiLabel(void)  : GuiItem("label")
{
	caption = "";
	font = style->getNormalFont();
	transparent = true;
	stringBuffer = 0;
}



GuiLabel::~GuiLabel(void)
{
}

void GuiLabel::setCaption(char* m_caption)
{
	caption = m_caption;
	renderCaption();
}

char* GuiLabel::getCaption(void)
{
	return caption;
}

void GuiLabel::setFont(SFont *m_font)
{
	font = m_font;
}

void GuiLabel::renderCaption(void)
{
	if(stringBuffer != 0)
	{
		delete stringBuffer;
	}

	stringBuffer = font->renderText(caption, foreground);
}

void GuiLabel::autosize(void)
{
	if(stringBuffer == 0)
	{
		renderCaption();
	}

	width = stringBuffer->getWidth();
	height = stringBuffer->getHeight();
}

void GuiLabel::setTransparent(bool m_transparent)
{
	transparent = m_transparent;
}

bool GuiLabel::getTransparent(void)
{
	return transparent;
}

Surface *GuiLabel::render(void)
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
