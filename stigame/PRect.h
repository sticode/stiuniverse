#pragma once
#include "SPrimitive.h"
#include "SRect.h"
namespace StiGame
{
class PRect :
	public SPrimitive,
	public SRect
{
public:
	PRect(void);
	~PRect(void);
	void draw(SDL_Surface *, SColor *);
	void fill(SDL_Surface *, SColor *);
	void draw(SDL_Renderer *renderer, SColor *color);
    void fill(SDL_Renderer *renderer, SColor *color);
};
}

