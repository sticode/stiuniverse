#ifndef SPACEVESSEL_H
#define SPACEVESSEL_H

#include <string>
#include <vector>
#include "GameUnit.h"
#include "MissileThrower.h"
namespace StiUniverse
{


class SpaceVessel :
    public StiGame::GameUnit
{
    public:
        const static unsigned int MISSILE_THROWER_MAX = 3;
        SpaceVessel();
        virtual ~SpaceVessel();

        virtual void spawnVessel(int v_width, int v_height);

        virtual void moveUnit(StiGame::SDirection m_direction);
        StiGame::DirectionSprite* getSprite(void);
        void loadSprite(SDL_Renderer *renderer);
        StiGame::BaseMissile* throwMissile(int index, SDL_Renderer *renderer, double angle);
        virtual void tick(void);
        std::string getVesselName(void);
    protected:
        int _tick;
        std::string vessel_name;
        StiGame::DirectionSprite *sprite;

        //need a more elegant thing than only the enum type
        //maybe a class that handle missile cooldown or energy levels
        std::vector<MissileThrower*> mthrowers;
        void initialize(void);
    private:
};

}

#endif // SPACEVESSEL_H
