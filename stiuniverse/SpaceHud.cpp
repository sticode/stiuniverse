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

    lblX->set(400, 10);
    lblY->set(400, 30);

    hpBar = new ProgressBar();

    hpBar->setWidth(300);
    hpBar->setHeight(15);
    hpBar->set(90, 10);
    hpBar->setMax(200);
    hpBar->setCurrent(170);

    hpBarTextColor = new SColor(255, 5, 5);

    lblHpBar = new Label();
    lblHpBar->setForeground(hpBarTextColor);
    lblHpBar->setCaption("HP");

    lblHpBar->set(90, 12);

    add(label1);
    add(lblX);
    add(lblY);
    add(hpBar);
    add(lblHpBar);
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
