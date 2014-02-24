#pragma once
#include "SPrimitive.h"
#include "math.h"
namespace StiGame
{
class PLine :
	public SPrimitive
{
public:
	PLine(void);
	~PLine(void);
	void fill(SDL_Surface*,SColor*);
	void draw(SDL_Surface*,SColor*);
	void draw(SDL_Renderer *renderer, SColor *color);
    void fill(SDL_Renderer *renderer, SColor *color);
	void set1(int,int);
	void set2(int,int);
	int getX1(void);
	int getY1(void);
	int getX2(void);
	int getY2(void);
	int getSize(void);
	void setSize(int);
protected:
	void fillHLine(SDL_Surface*, SColor*);
	void fillVLine(SDL_Surface*, SColor*);
	void fillTanLine(SDL_Surface*,SColor*);
	void switchPoints(void);
	int x1,y1,x2,y2,size;
};

}

