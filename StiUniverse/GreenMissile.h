#ifndef GREENMISSILE_H
#define GREENMISSILE_H
#include "BaseMissile.h"
namespace StiUniverse
{

class GreenMissile :
    public StiGame::BaseMissile
{
    public:
        GreenMissile();
        GreenMissile(SDL_Renderer *m_renderer, int m_startingX, int m_startingY, double m_angle);
        virtual ~GreenMissile();
    protected:
    private:
};

}

#endif // GREENMISSILE_H
