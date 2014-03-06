#include "Cursor.h"

namespace StiGame
{

Cursor::Cursor()
{
	cursor = SDL_GetCursor(); //default cursor
}

Cursor::Cursor(SDL_Cursor *m_cursor)
{
	cursor = m_cursor;
}

Cursor::~Cursor()
{
	//free this ?
	SDL_Cursor *d_cursor = SDL_GetCursor();
	
	if(cursor != d_cursor)
	{
		SDL_FreeCursor(cursor);
	}
}

const Uint8* Cursor::getData(void)
{
	return cursor->data;
}

const Uint8* Cursor::getMask(void)
{
	return cursor->mask;
}

int Cursor::getWidth(void)
{
	return cursor->w;
}

int Cursor::getHeight(void)
{
	return cursor->h;
}

int Cursor::getHotX(void)
{
	return cursor->hot_x;
}

int Cursor::getHotY(void)
{
	return cursor->hot_y;
}

void Cursor::setData(const Uint8* data)
{
	cursor->data = data;
}

void Cursor::setMask(const Uint8* mask)
{
	cursor->mask = mask;
}

void Cursor::setWidth(int width)
{
	cursor->w = width;
}

void Cursor::setHeight(int height)
{
	cursor->h = height;
}

void Cursor::setHotX(int hotX)
{
	cursor->hot_x = hotX;
}

void Cursor::setHotY(int hotY)
{
	cursor->hot_y = hotY;
}

SDL_Cursor* Cursor::getSDLCursor(void)
{
	return cursor;
}


}