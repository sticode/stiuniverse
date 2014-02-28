#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GuiState.h"
#include "EventListener.h"
#include "Button.h"

namespace StiUniverse
{

class MainMenuState :
    public StiGame::Gui::GuiState,
    public StiGame::EventListener
{
    public:
        MainMenuState();
        virtual ~MainMenuState();
        void handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *evt);
    protected:
        StiGame::Gui::Button btnStart;
        StiGame::Gui::Button btnQuit;
    private:
};

}

#endif // MAINMENUSTATE_H
