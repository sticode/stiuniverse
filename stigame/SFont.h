#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "Surface.h"
#include "Color.h"
#include <string>
namespace StiGame
{

/// \class SFont
/// \brief Wrapper of a SDL_TTFFont
class SFont
{
private:
	/// \brief TTF_Font pointer
	TTF_Font *font;
	/// \brief Ttf file path
	const char *path;
	/// \brief Font size
	int size;
public:
	/// \brief Empty font
	SFont(void);
	/// \brief Load a ttf file with specified font size
	SFont(const char* m_path,int m_size);
	
	SFont(SDL_RWops *rw, int m_size);
	
	/// \brief Destructor
	~SFont(void);
	/// \brief Get the font size value
	/// \return font size
	int getSize(void);
	/// \brief Get the ttf file path
	/// \return ttf path
	const char *getPath(void);
	/// \brief Get the TTF_Font pointer
	/// \return TTF_Font pointer
	TTF_Font *getFont(void);
	/// \brief Render the specified string and color into a surface
	/// \param caption Text to render
	/// \param color SColor pointer
	Surface *renderText(const char *caption, Color *color);
	/// \brief Render the specified string and color into a surface
	/// \param caption Text to render
	/// \param color SColor pointer
	Surface *renderText(std::string caption, Color *color);
	
	Surface *renderTextShaded(std::string caption, Color *color, Color *bg);
	Surface *renderTextBlended(std::string caption, Color *color);
	
	int getFontStyle(void);
	void setFontStyle(int style);
};

}
