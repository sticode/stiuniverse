#ifndef OPTIONMENUSTATE_H
#define OPTIONMENUSTATE_H

#include "GuiState.h"
#include "Button.h"
#include "KeyBind.h"
#include "EventListener.h"
namespace StiUniverse
{

class OptionMenuState :
    public StiGame::Gui::GuiState,
    public StiGame::EventListener
{
    public:
        OptionMenuState();
        virtual ~OptionMenuState();
    protected:
    void handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *args);
    StiGame::Gui::KeyBind keyUp;
    StiGame::Gui::KeyBind keyDown;
    StiGame::Gui::KeyBind keyLeft;
    StiGame::Gui::KeyBind keyRight;
    StiGame::Gui::Button btnBack;
    private:
};

}

#endif // OPTIONMENUSTATE_H
