#ifndef GAMEOVERLAY_H
#define GAMEOVERLAY_H

#include "OverlayMenu.h"
#include "Button.h"
#include "EventListener.h"
#include "MainState.h"

namespace StiGame
{
class GameOverlay :
    public Gui::OverlayMenu,
    public EventListener
{
    public:
        GameOverlay();
        virtual ~GameOverlay();
        void handleEvent(EventThrower *src, SEventArgs *evt);
        void setState(MainState *m_state);
    protected:
        Gui::Button resumeButton;
        Gui::Button quitButton;
        MainState *state;
    private:
};

}

#endif // GAMEOVERLAY_H
