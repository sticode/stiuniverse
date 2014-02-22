#include "SpaceHud.h"

using namespace StiGame;
using namespace StiGame::Gui;

namespace StiUniverse
{


SpaceHud::SpaceHud() : OverlayFrame()
{
    //ctor
    background = new SColor(10, 10, 10);
    label1 = new Label();
    label1->setX(10);
    label1->setY(10);
    label1->setCaption("allo");
    add(label1);

}

SpaceHud::~SpaceHud()
{
    //dtor
}

void SpaceHud::setVessel(SpaceVessel *m_vessel)
{
    vessel = m_vessel;
    label1->setCaption(vessel->getVesselName());
}


}
