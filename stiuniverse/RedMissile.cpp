#include "RedMissile.h"
#include "MathTK.h"
namespace StiGame
{

RedMissile::RedMissile() : BaseMissile()
{

}

RedMissile::RedMissile(SDL_Renderer *m_renderer, int m_startingX, int m_startingY, double m_angle)
{
    renderer = m_renderer;
    startingX = m_startingX;
    startingY = m_startingY;
    angle = Math::TK::CreateAngle(Math::AU_RADIAN, m_angle);
    currentX = startingX;
    currentY = startingY;

    gfxName = "0";
    loadGfx(gfxName);
    //ctor
    speed = 15;
    maxLength = 400;
    ended = false;
}

RedMissile::~RedMissile()
{
    //dtor
}

}
