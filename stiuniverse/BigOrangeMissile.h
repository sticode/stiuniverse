#ifndef BIGORANGEMISSILE_H
#define BIGORANGEMISSILE_H

#include "BaseMissile.h"

namespace StiUniverse
{

class BigOrangeMissile :
    public StiGame::BaseMissile
{
    public:
        BigOrangeMissile();
        BigOrangeMissile(SDL_Renderer *m_renderer, int m_startingX, int m_startingY, double m_angle);
        virtual ~BigOrangeMissile();
    protected:
    private:
};

}

#endif // BIGORANGEMISSILE_H
