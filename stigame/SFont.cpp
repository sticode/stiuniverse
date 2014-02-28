
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


SFont::SFont(SDL_RWops *rw, int m_size)
{
	font = 0;
	size = m_size;
	path = "rw_ops";
	font = TTF_OpenFontRW(rw, 1, size);
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

Surface *SFont::renderText(std::string caption, Color *color)
{
    return renderText(caption.c_str(), color);
}

Surface *SFont::renderText(const char* text, Color *color)
{
	SDL_Surface *txtsur = TTF_RenderText_Solid(font, text, color->getSDLColor());
	Surface *sur = new Surface(txtsur);
	sur->setReleaseSurface(true);
	return sur;
}

Surface *SFont::renderTextShaded(std::string caption, Color *color, Color *bg)
{
	SDL_Surface *txtsur = TTF_RenderText_Shaded(font, caption.c_str(), color->getSDLColor(), bg->getSDLColor());
	Surface *sur = new Surface(txtsur);
	sur->setReleaseSurface(true);
	return sur;
}

Surface *SFont::renderTextBlended(std::string caption, Color *color)
{
	SDL_Surface *txtsur = TTF_RenderText_Blended(font, caption.c_str(), color->getSDLColor());
	Surface *sur = new Surface(txtsur);
	sur->setReleaseSurface(true);
	return sur;
}

int SFont::getFontStyle(void)
{
	return TTF_GetFontStyle(font);
}

void SFont::setFontStyle(int style)
{
	TTF_SetFontStyle(font, style);
}

}
