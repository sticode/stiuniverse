#include "Rectangle.h"

namespace StiGame
{

Rectangle::Rectangle(void)
{
	width = 0;
	height = 0;
	x = 0;
	y = 0;
}

Rectangle::Rectangle(int m_x, int m_y, int m_width, int m_height)
{
	x = m_x;
	y = m_y;
	width = m_width;
	height = m_height;

}

Point* Rectangle::getLeftTop(void)
{
    return new Point(x, y);
}
Point* Rectangle::getLeftBottom(void)
{
    return new Point(x, y + height);
}
Point* Rectangle::getRightTop(void)
{
    return new Point(x + width, y);
}
Point* Rectangle::getRightBottom(void)
{
    return new Point(x + width, y + height);
}


void Rectangle::fromSDLRect(SDL_Rect *rect)
{
	x = rect->x;
	y = rect->y;
	width = rect->w;
	height = rect->h;
}

SDL_Rect *Rectangle::getSDLRect(void)
{
	SDL_Rect *rect = new SDL_Rect();
	rect->x = x;
	rect->y = y;
	rect->w = width;
	rect->h = height;

	return rect;
}

bool Rectangle::contains(Point *pt)
{
	return contains(pt->getX(), pt->getY());
}

void Rectangle::updateSDLRect(SDL_Rect *rect)
{
    rect->x = x;
    rect->y = y;
    rect->w = width;
    rect->h = height;
}

bool Rectangle::contains(int p_x, int p_y)
{
	return ( ( p_x >= x && p_x <= x + width ) && ( p_y >= y && p_y <= y + height ) );
}

bool Rectangle::intersect(Rectangle *rect)
{
    bool xlap = Rectangle::valueInRange(x, rect->getX(), rect->getX() + rect->getWidth()) ||
                Rectangle::valueInRange(rect->getX(), x, x + width);
    bool ylap = Rectangle::valueInRange(y, rect->getY(), rect->getY() + rect->getHeight()) ||
                Rectangle::valueInRange(rect->getY(), y, y + height);

    return xlap && ylap;

}

bool Rectangle::valueInRange(int value, int min, int max)
{
    return (value >= min) || (value <= max);
}

Rectangle::~Rectangle(void)
{
}


}
