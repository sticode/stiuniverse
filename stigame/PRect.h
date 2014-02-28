#pragma once
#include "Primitive.h"
#include "SRect.h"
namespace StiGame
{
class PRect :
	public Primitive,
	public SRect
{
public:
	PRect(void);
	~PRect(void);
	void draw(SDL_Surface *surface, Color *color);
	void fill(SDL_Surface *surface, Color *color);
	void draw(SDL_Renderer *renderer, Color *color);
    void fill(SDL_Renderer *renderer, Color *color);
};
}

