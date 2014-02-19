#include "SRect.h"

namespace StiGame
{

SRect::SRect(void)
{
	width = 0;
	height = 0;
	x = 0;
	y = 0;
}

SRect::SRect(int m_x, int m_y, int m_width, int m_height)
{
	x = m_x;
	y = m_y;
	width = m_width;
	height = m_height;

}

Point* SRect::getLeftTop(void)
{
    return new Point(x, y);
}
Point* SRect::getLeftBottom(void)
{
    return new Point(x, y + height);
}
Point* SRect::getRightTop(void)
{
    return new Point(x + width, y);
}
Point* SRect::getRightBottom(void)
{
    return new Point(x + width, y + height);
}


void SRect::fromSDLRect(SDL_Rect *rect)
{
	x = rect->x;
	y = rect->y;
	width = rect->w;
	height = rect->h;
}

SDL_Rect *SRect::getSDLRect(void)
{
	SDL_Rect *rect = new SDL_Rect();
	rect->x = x;
	rect->y = y;
	rect->w = width;
	rect->h = height;

	return rect;
}

bool SRect::contains(Point *pt)
{
	return contains(pt->getX(), pt->getY());
}

void SRect::updateSDLRect(SDL_Rect *rect)
{
    rect->x = x;
    rect->y = y;
    rect->w = width;
    rect->h = height;
}

bool SRect::contains(int p_x, int p_y)
{
	return ( ( p_x >= x && p_x <= x + width ) && ( p_y >= y && p_y <= y + height ) );
}

bool SRect::intersect(SRect *rect)
{
    bool xlap = SRect::valueInRange(x, rect->getX(), rect->getX() + rect->getWidth()) ||
                SRect::valueInRange(rect->getX(), x, x + width);
    bool ylap = SRect::valueInRange(y, rect->getY(), rect->getY() + rect->getHeight()) ||
                SRect::valueInRange(rect->getY(), y, y + height);

    return xlap && ylap;

}

bool SRect::valueInRange(int value, int min, int max)
{
    return (value >= min) || (value <= max);
}

SRect::~SRect(void)
{
}


}
