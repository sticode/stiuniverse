#include "BatVessel.h"
#include "RedMissile.h"
#include "GreenMissile.h"
using namespace StiGame;

namespace StiUniverse
{

BVMissileLauncher1::BVMissileLauncher1()
{

}

BVMissileLauncher1::~BVMissileLauncher1()
{

}

BaseMissile* BVMissileLauncher1::throwMissile(int m_x, int m_y, double angle)
{
    return new RedMissile(renderer, m_x, m_y, angle);
}


BVMissileLauncher2::BVMissileLauncher2()
{

}

BVMissileLauncher2::~BVMissileLauncher2()
{

}

BaseMissile* BVMissileLauncher2::throwMissile(int m_x, int m_y, double angle)
{
    return new GreenMissile(renderer, m_x, m_y, angle);
}



BatVessel::BatVessel()
{
    //ctor
    initialize();
    gfxName = "vessel0";
    vessel_name = "Bat Vessel";
    speed = 25;
    mthrowers.push_back(new BVMissileLauncher1());
    mthrowers.push_back(new BVMissileLauncher2());
    //
}

BatVessel::~BatVessel()
{
    //dtor
}

}
