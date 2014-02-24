
#include "SPrimitive.h"
#include "SDL.h"
#include "SColor.h"
#include "Surface.h"
namespace StiGame
{
SPrimitive::SPrimitive(void)
{
}


SPrimitive::~SPrimitive(void)
{
}


void SPrimitive::draw(Surface *surface, SColor *color)
{
	draw(surface->getSDLSurface(), color);
}

void SPrimitive::fill(Surface *surface, SColor *color)
{
	fill(surface->getSDLSurface(), color);
}

void SPrimitive::setPixel(SDL_Surface *surface, int px, int py, Uint32 pixel)
{
	Uint8 *target_pixel = (Uint8 *)surface->pixels + py * surface->pitch + px * 4;
	*(Uint32 *)target_pixel = pixel;
}

}
