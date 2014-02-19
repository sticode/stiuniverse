#pragma once
#include "SDL.h"

namespace StiGame
{
/// \class SColor
/// \brief Class to map color into SDL
class SColor
{
public:
	/// \brief Empty color
	SColor(void);
	/// \brief Create a new RGB color
	/// \param r red
	/// \param g green
	/// \param b blue
	SColor(Uint8 r,Uint8 g,Uint8 b);
    /// \brief Create a new RGB color
	/// \param r red
	/// \param g green
	/// \param b blue
	/// \param a alpha
	SColor(Uint8 r,Uint8 g,Uint8 b, Uint8 a);
	/// \brief Destructor
	~SColor(void);
	/// \brief is the value is Uint32 mapped
	/// \return mapped or not
	bool isMapped(void);
	/// \brief Map the color with the specified format
	/// \param format PixelFormat
	void mapColor(SDL_PixelFormat *format);
	/// \brief Get SDL_Color value
	/// \return SDL_Color
	SDL_Color getColor(void);
	/// \brief Get the Uint32 mapped color
	/// \return Uint32 color
	Uint32 getMap(void);
    /// \brief Get the red value
    /// \return red value (0-255)
    Uint8 getRed(void);
    /// \brief Get the blue value
    /// \return blue value (0-255)
    Uint8 getBlue(void);
    /// \brief Get the green value
    /// \return green value (0-255)
    Uint8 getGreen(void);
    /// \brief Get the alpha value
    /// \return alpha value (0-255)
    Uint8 getAlpha(void);
protected:
	/// \brief Red byte value
	Uint8 red;
	/// \brief Blue byte value
	Uint8 blue;
	/// \brief Green byte value
	Uint8 green;
	/// \brief Alpha blending
	Uint8 alpha;
	/// \brief Color map value
	Uint32 map;
	/// \brief Mapped or not
	bool mapped;
};

}
