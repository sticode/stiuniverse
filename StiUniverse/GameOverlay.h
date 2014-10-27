#ifndef GAMEOVERLAY_H
#define GAMEOVERLAY_H

#include "OverlayMenu.h"
#include "Button.h"
#include "EventListener.h"
#include "MainState.h"

namespace StiUniverse
{
class GameOverlay :
    public StiGame::Gui::OverlayMenu,
    public StiGame::EventListener
{
    public:
        GameOverlay();
        virtual ~GameOverlay();
        bool handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *evt);
        void setState(MainState *m_state);
    protected:
        StiGame::Gui::Button resumeButton;
        StiGame::Gui::Button quitButton;
        MainState *state;
    private:
};

}

#endif // GAMEOVERLAY_H
