#ifndef SPACEHUD_H
#define SPACEHUD_H

#include "OverlayFrame.h"
#include "Label.h"
#include "ProgressBar.h"
#include "SpaceVessel.h"

namespace StiUniverse
{

class SpaceHud :
    public StiGame::Gui::OverlayFrame
{
    public:
        SpaceHud();
        virtual ~SpaceHud();
        void setVessel(SpaceVessel *m_vessel);
        void tick(void);
    protected:
        StiGame::Gui::Label *label1;
        StiGame::Gui::Label *lblX;
        StiGame::Gui::Label *lblY;
        StiGame::Gui::ProgressBar *hpBar;
        StiGame::Gui::Label *lblHpBar;
		StiGame::Gui::Label *lblTxtHp;
        StiGame::Color *hpBarTextColor;
        SpaceVessel *vessel;
    private:
};

}

#endif // SPACEHUD_H
