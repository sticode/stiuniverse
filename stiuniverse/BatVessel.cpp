#include "BatVessel.h"
namespace StiGame
{

BatVessel::BatVessel()
{
    //ctor
    initialize();
    gfxName = "vessel0";
    vessel_name = "Bat Vessel";
    speed = 25;

    //
}

BatVessel::~BatVessel()
{
    //dtor
}

}
