
#include "SFont.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "Surface.h"
namespace StiGame
{

SFont::SFont()
{
	font = 0;
	size = -1;
	path = "";
}

SFont::SFont(const char *m_path, int m_size)
{
	size = m_size;
	path = m_path;
	font = TTF_OpenFont(m_path, m_size);
}



SFont::~SFont(void)
{
	if(font != 0)
	{
		TTF_CloseFont(font);
	}
}

int SFont::getSize(void)
{
	return size;
}
const char *SFont::getPath(void)
{
	return path;
}
TTF_Font *SFont::getFont(void)
{
	return font;
}

Surface *SFont::renderText(std::string caption, SColor *color)
{
    return renderText(caption.c_str(), color);
}

Surface *SFont::renderText(const char* text, SColor *color)
{
	SDL_Surface *txtsur = TTF_RenderText_Solid(font, text, color->getColor());
	Surface *sur = new Surface(txtsur);
	sur->setReleaseSurface(true);
	return sur;
}

}
