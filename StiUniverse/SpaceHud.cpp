#include "SpaceHud.h"
#include "String.h"

using namespace StiGame;
using namespace StiGame::Gui;

namespace StiUniverse
{


SpaceHud::SpaceHud() : OverlayFrame()
{
    //ctor
    background = new Color(10, 10, 10);
    label1 = new Label();
    label1->setX(10);
    label1->setY(10);
    label1->setCaption("allo");

    lblX = new Label();

    lblY = new Label();

    lblX->setPoint(400, 10);
    lblY->setPoint(400, 30);

    hpBar = new ProgressBar();

    hpBar->setWidth(300);
    hpBar->setHeight(15);
    hpBar->setPoint(90, 10);
    hpBar->setMax(200);
    hpBar->setCurrent(170);

    hpBarTextColor = new Color(255, 5, 5);

    lblHpBar = new Label();
    lblHpBar->setForeground(hpBarTextColor);
    lblHpBar->setCaption("HP");

    lblHpBar->setPoint(90, 12);

	lblTxtHp = new Label();
	lblTxtHp->setForeground(hpBarTextColor);
	lblTxtHp->setCaption("0/0");
	lblTxtHp->setPoint(hpBar->getX() + hpBar->getWidth() + 2, hpBar->getY() + (hpBar->getHeight() - lblTxtHp->getHeight())/2);

    add(label1);
    add(lblX);
    add(lblY);
    add(hpBar);
    add(lblHpBar);
	add(lblTxtHp);
}

SpaceHud::~SpaceHud()
{
    //dtor
}

void SpaceHud::setVessel(SpaceVessel *m_vessel)
{
    vessel = m_vessel;
    label1->setCaption(vessel->getVesselName());
	lblTxtHp->setCaption(String::to_string(vessel->getCurrentHp()) + "/" + String::to_string(vessel->getMaxHp()));
}

void SpaceHud::tick(void)
{
    lblX->setCaption("X : " + String::to_string(vessel->getX()));
    lblY->setCaption("Y : " + String::to_string(vessel->getY()));
	lblTxtHp->setCaption(String::to_string(vessel->getCurrentHp()) + "/" + String::to_string(vessel->getMaxHp()));
}


}
