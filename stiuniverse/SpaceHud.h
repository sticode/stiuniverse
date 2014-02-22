#ifndef SPACEHUD_H
#define SPACEHUD_H

#include "OverlayFrame.h"
#include "Label.h"
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
    protected:
        StiGame::Gui::Label *label1;
        SpaceVessel *vessel;
    private:
};

}

#endif // SPACEHUD_H
