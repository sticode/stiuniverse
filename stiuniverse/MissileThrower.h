#ifndef MISSILETHROWER_H
#define MISSILETHROWER_H

#include "BaseMissile.h"

namespace StiUniverse
{

class MissileThrower
{
    public:
        MissileThrower();
        MissileThrower(SDL_Renderer *m_renderer);

        void setRenderer(SDL_Renderer *m_renderer);
        SDL_Renderer* getRenderer(void);

        virtual ~MissileThrower();
        virtual bool isReady(void);
        virtual StiGame::BaseMissile* throwMissile(int m_x, int m_y, double angle) = 0;
    protected:
        SDL_Renderer *renderer;
        bool ready;
    private:
};

}

#endif // MISSILETHROWER_H
