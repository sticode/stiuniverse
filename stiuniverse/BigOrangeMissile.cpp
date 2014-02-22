#include "BigOrangeMissile.h"
#include "MathTK.h"

using namespace StiGame;

namespace StiUniverse
{

    BigOrangeMissile::BigOrangeMissile() : BaseMissile()
    {

    }

    BigOrangeMissile::BigOrangeMissile(SDL_Renderer *m_renderer, int m_startingX, int m_startingY, double m_angle)
    {
        renderer = m_renderer;
        startingX = m_startingX;
        startingY = m_startingY;
        angle = Math::TK::CreateAngle(Math::AU_RADIAN, m_angle);
        currentX = startingX;
        currentY = startingY;

        gfxName = "2";
        loadGfx(gfxName);
        //ctor
        speed = 12;
        maxLength = 600;
        ended = false;
    }

    BigOrangeMissile::~BigOrangeMissile()
    {

    }

}
