#ifndef REDMISSILE_H
#define REDMISSILE_H
#include "BaseMissile.h"
namespace StiUniverse
{

class RedMissile :
    public StiGame::BaseMissile
{
    public:
        RedMissile();
        RedMissile(SDL_Renderer *m_renderer, int m_startingX, int m_startingY, double m_angle);
        virtual ~RedMissile();
    protected:
    private:
};

}

#endif // REDMISSILE_H
