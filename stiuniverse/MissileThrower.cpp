#include "MissileThrower.h"
namespace StiGame
{

MissileThrower::MissileThrower()
{
    //ctor
    ready = true;
    renderer = 0;
}

MissileThrower::MissileThrower(SDL_Renderer *m_renderer)
{
    ready = true;
    renderer = m_renderer;
}

bool MissileThrower::isReady(void)
{
    return ready;
}

void MissileThrower::setRenderer(SDL_Renderer *m_renderer)
{
    renderer = m_renderer;
}

SDL_Renderer* MissileThrower::getRenderer(void)
{
    return renderer;
}

MissileThrower::~MissileThrower()
{
    //dtor
}

}
