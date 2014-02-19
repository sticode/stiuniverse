#pragma once
#include "SDL.h"
#include "SColor.h"
#include "SPrimitive.h"
namespace StiGame
{
	/// \class PCircle
	/// \brief Circle primitive class
class PCircle : public SPrimitive
{
private:
	int x,y;
	double radius;

public:
	/// \brief Empty circle
	PCircle(void);
	/// \brief Create a circle with specified middle
	/// \param m_x middle x
	/// \param m_y middle y
	PCircle(int m_x,int m_y);
	/// \brief Create a circle with specified middle and radius
	/// \param m_x middle x
	/// \param m_y middle y
	/// \param m_radius radius (px)
	PCircle(int m_x,int m_y, double m_radius);
	/// \brief Destructor
	~PCircle(void);
	void fill(SDL_Surface *, SColor *);
	void draw(SDL_Surface *, SColor *);

    void draw(SDL_Renderer *renderer, SColor *color);
    void fill(SDL_Renderer *renderer, SColor *color);

	int getX(void);
	void setX(int m_x);
	int getY(void);
	void setY(int m_y);
	void setMiddle(int,int);

	double getRadius(void);
	void setRadius(double);
};
}
