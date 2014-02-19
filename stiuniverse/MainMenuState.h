#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GuiState.h"
#include "EventListener.h"
#include "GuiButton.h"

namespace StiGame
{

class MainMenuState :
    public GuiState,
    public EventListener
{
    public:
        MainMenuState();
        virtual ~MainMenuState();
        void handleEvent(EventThrower *src, SEventArgs *evt);
    protected:
        GuiButton btnStart;
        GuiButton btnQuit;
    private:
};

}

#endif // MAINMENUSTATE_H
