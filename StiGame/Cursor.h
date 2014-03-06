#ifndef CURSOR_H
#define CURSOR_H

#include "SDL.h"

namespace StiGame
{
//WIP not added to cbp
class Cursor
{
public:
	Cursor();
	Cursor(SDL_Cursor *m_cursor);
	//todo : add a ctor for CreateCursor
	virtual ~Cursor();

	const Uint8* getData(void);
	const Uint8* getMask(void);
	int getWidth(void);
	int getHeight(void);
	int getHotX(void);
	int getHotY(void);
	
	void setData(const Uint8* data);
	void setMask(const Uint8* mask);
	void setWidth(int width);
	void setHeight(int height);
	void setHotX(int hotX);
	void setHotY(int hotY);
	
	SDL_Cursor* getSDLCursor(void);
	
protected:
	SDL_Cursor *cursor;

};

}

#endif