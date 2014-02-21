#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GuiState.h"
#include "EventListener.h"
#include "Button.h"

namespace StiGame
{

class MainMenuState :
    public Gui::GuiState,
    public EventListener
{
    public:
        MainMenuState();
        virtual ~MainMenuState();
        void handleEvent(EventThrower *src, SEventArgs *evt);
    protected:
        Gui::Button btnStart;
        Gui::Button btnQuit;
    private:
};

}

#endif // MAINMENUSTATE_H
