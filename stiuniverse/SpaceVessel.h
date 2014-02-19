#ifndef SPACEVESSEL_H
#define SPACEVESSEL_H

#include <string>
#include <vector>
#include "GameUnit.h"
#include "MissileThrower.h"
namespace StiGame
{


class SpaceVessel :
    public GameUnit
{
    public:
        const static unsigned int MISSILE_THROWER_MAX = 3;
        SpaceVessel();
        virtual ~SpaceVessel();

        virtual void spawnVessel(int v_width, int v_height);

        virtual void moveUnit(SDirection m_direction);
        DirectionSprite* getSprite(void);
        void loadSprite(SDL_Renderer *renderer);
        BaseMissile* throwMissile(int index, SDL_Renderer *renderer, double angle);
        virtual void tick(void);
    protected:
        int _tick;
        std::string vessel_name;
        DirectionSprite *sprite;

        //need a more elegant thing than only the enum type
        //maybe a class that handle missile cooldown or energy levels
        std::vector<MissileThrower*> mthrowers;
        void initialize(void);
    private:
};

}

#endif // SPACEVESSEL_H
