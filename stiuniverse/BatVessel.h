#ifndef BATVESSEL_H
#define BATVESSEL_H

#include "SpaceVessel.h"

namespace StiUniverse
{

class BatVessel :
    public SpaceVessel
{
    public:
        BatVessel();
        virtual ~BatVessel();
    protected:
    private:
};

class BVMissileLauncher1 :
    public MissileThrower
{
    public:
        BVMissileLauncher1();
        virtual ~BVMissileLauncher1();
        StiGame::BaseMissile* throwMissile(int m_x, int m_y, double angle);

};

class BVMissileLauncher2 :
    public MissileThrower
{
    public:
        BVMissileLauncher2();
        virtual ~BVMissileLauncher2();
        StiGame::BaseMissile* throwMissile(int m_x, int m_y, double angle);

};

}

#endif // BATVESSEL_H
