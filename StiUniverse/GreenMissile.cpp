#include "GreenMissile.h"
#include "MathTK.h"

using namespace StiGame;

namespace StiUniverse
{

GreenMissile::GreenMissile() : BaseMissile()
{

}

GreenMissile::GreenMissile(SDL_Renderer *m_renderer, int m_startingX, int m_startingY, double m_angle)
{
    renderer = m_renderer;
    startingX = m_startingX;
    startingY = m_startingY;
    angle = Math::TK::CreateAngle(Math::AU_RADIAN, m_angle);
    currentX = startingX;
    currentY = startingY;

    gfxName = "1";
    loadGfx(gfxName);
    //ctor
    speed = 80;
    maxLength = 1500;
    ended = false;
}

GreenMissile::~GreenMissile()
{
    //dtor
}

}
