#include "GuiOverlay.h"
#include "PLine.h"

namespace StiGame
{

const int GuiOverlay::DEFAULT_OFFSET = 4;

GuiOverlay::GuiOverlay() : GuiItem("GuiOverlay")
{
    //ctor
	position = OP_MIDDLE;
	visible = false;
}

GuiOverlay::~GuiOverlay()
{
    //dtor
}

OverlayPosition GuiOverlay::getPosition(void)
{
	return position;
}

void GuiOverlay::setPosition(OverlayPosition m_position)
{
	position = m_position;
}

void GuiOverlay::fixPosition(int m_width, int m_height)
{
	int n_height = DEFAULT_OFFSET;
	std::list<GuiItem*>::iterator lit(items.begin()), lend(items.end());
	for(;lit!=lend;++lit)
	{
		if((*lit)->getWidth() == 0 && (*lit)->getHeight() == 0)
		{
			delete (*lit)->render();
		}
	
		if(width == 0)
		{
			width = (*lit)->getWidth() + DEFAULT_OFFSET*2;
		}
		
		(*lit)->setX( (width - (*lit)->getWidth()) / 2 );
		(*lit)->setY(n_height);
			
		n_height += ((*lit)->getHeight() + DEFAULT_OFFSET);
	}
	
	height = n_height;

	switch(position)
	{
		case OP_MIDDLE:
			x = (m_width - width) / 2;
			y = (m_height - height) / 2;
		break;

		case OP_TOP_LEFT_CORNER:
			x = 0;
			y = 0;
		break;

		case OP_TOP_RIGHT_CORNER:
			x = m_width - width;
			y = 0;
		break;

		case OP_BOTTOM_LEFT_CORNER:
			x = 0;
			y = m_height - height;
		break;

		case OP_BOTTOM_RIGHT_CORNER:
			x = m_width - width;
			y = m_height - height;
		break;
	}
	
}

void GuiOverlay::add(GuiItem *item)
{
	items.push_back(item);
}

GuiItem* GuiOverlay::getLastItem(void)
{
	int y = -1;
	GuiItem *item = 0;

	std::list<GuiItem*>::iterator lit(items.begin()), lend(items.end());

	for(;lit!=lend;++lit)
	{
		if((*lit)->getY() > y)
		{
			y = (*lit)->getY();
			item = (*lit);
		}
	}

	return item;
}

void GuiOverlay::onMouseMotion(Point *relp)
{
    std::list<GuiItem*>::iterator lit(items.begin()), lend(items.end());

    for(;lit!=lend;++lit)
    {
        if((*lit)->contains(relp))
        {
            Point *pt = new Point(relp->getX() - (*lit)->getX(), relp->getY() - (*lit)->getY());

            (*lit)->onMouseMotion(pt);
			(*lit)->setMouseOver(true);

            delete pt;
        }
		else
		{
			if((*lit)->getMouseOver())
			{
				(*lit)->setMouseOver(false);
			}
		}
    }
}

void GuiOverlay::onClick(Point *relp)
{
    std::list<GuiItem*>::iterator lit(items.begin()), lend(items.end());

    for(;lit!=lend;++lit)
    {
        if((*lit)->contains(relp))
        {
            Point *pt = new Point(relp->getX() - (*lit)->getX(), relp->getY() - (*lit)->getY());

            (*lit)->onClick(pt);

            delete pt;
        }
    }
}

bool GuiOverlay::isVisible(void)
{
    return visible;
}

void GuiOverlay::setVisible(bool m_visible)
{
    visible = m_visible;
}

Surface* GuiOverlay::render(void)
{
    Surface *buffer = new Surface(width, height);
    buffer->fill(background);
    std::list<GuiItem*>::iterator lit(items.begin()), lend(items.end());

    SDL_Rect *src = new SDL_Rect();
    SDL_Rect *dst = new SDL_Rect();
    for(;lit!=lend;++lit)
    {
        Surface *ibuf = (*lit)->render();
        ibuf->updateSDLRect(src);
        ibuf->updateSDLRect(dst, (*lit)->getX(), (*lit)->getY());

        buffer->blit(ibuf, src, dst);

        delete ibuf;
    }

    delete src;
    delete dst;

	//border
	PLine line = PLine();
	line.set1(0,0);
	line.set2(width - 1, 0);

	line.draw(buffer->getSDLSurface(), foreground);

	line.set1(0,0);
	line.set2(0, height - 1);

	line.draw(buffer->getSDLSurface(), foreground);

	line.set1(width - 1, 0);
	line.set2(width - 1, height - 1);

	line.draw(buffer->getSDLSurface(), foreground);

	line.set1(0, height - 1);
	line.set2(width - 1, height - 1);

	line.draw(buffer->getSDLSurface(), foreground);

    return buffer;
}

}
