#ifndef GAMEOVERLAY_H
#define GAMEOVERLAY_H

#include "GuiOverlay.h"
#include "GuiButton.h"
#include "EventListener.h"
#include "MainState.h"

namespace StiGame
{
class GameOverlay :
    public GuiOverlay,
    public EventListener
{
    public:
        GameOverlay();
        virtual ~GameOverlay();
        void handleEvent(EventThrower *src, SEventArgs *evt);
        void setState(MainState *m_state);
    protected:
        GuiButton resumeButton;
        GuiButton quitButton;
        MainState *state;
    private:
};

}

#endif // GAMEOVERLAY_H
