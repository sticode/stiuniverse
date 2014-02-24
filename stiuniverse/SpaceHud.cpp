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

    lblX = new Label();

    lblY = new Label();

    lblX->set(100, 10);
    lblY->set(100, 30);

    add(label1);
    add(lblX);
    add(lblY);
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

void SpaceHud::tick(void)
{
    lblX->setCaption("X : " + std::to_string(vessel->getX()));
    lblY->setCaption("Y : " + std::to_string(vessel->getY()));
}


}
