
#include "SPrimitive.h"
#include "SDL.h"
#include "SColor.h"

namespace StiGame
{
SPrimitive::SPrimitive(void)
{
}


SPrimitive::~SPrimitive(void)
{
}




void SPrimitive::setPixel(SDL_Surface *surface, int px, int py, Uint32 pixel)
{
	Uint8 *target_pixel = (Uint8 *)surface->pixels + py * surface->pitch + px * 4;
	*(Uint32 *)target_pixel = pixel;
}

}
