#include "SColor.h"

namespace StiGame
{

SColor::SColor(void)
{
	red = 0;
	green = 0;
	blue = 0;
	mapped = false;
}

SColor::SColor(Uint8 r, Uint8 g, Uint8 b)
{
	red = r;
	green = g;
	blue = b;
	alpha = 255;
	mapped = false;
}

SColor::SColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	red = r;
	green = g;
	blue = b;
	alpha = a;
	mapped = false;
}



SColor::~SColor(void)
{
}

bool SColor::isMapped(void)
{
	return mapped;
}

Uint8 SColor::getRed(void)
{
    return red;
}

Uint8 SColor::getBlue(void)
{
    return blue;
}

Uint8 SColor::getGreen(void)
{
    return green;
}

Uint8 SColor::getAlpha(void)
{
    return alpha;
}


void SColor::mapColor(SDL_PixelFormat *format)
{
	if(!mapped)
	{
		map = SDL_MapRGB(format, red, blue, green);
		mapped = true;
	}
}

Uint32 SColor::getMap(void)
{
	return map;
}

SDL_Color SColor::getSDLColor(void)
{
	SDL_Color color = SDL_Color();
	color.r = red;
	color.b = blue;
	color.g = green;
	return color;
}

}
