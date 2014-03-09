#ifndef OPTIONMENUSTATE_H
#define OPTIONMENUSTATE_H

#include "GuiState.h"
#include "Button.h"
#include "KeyBind.h"
#include "Label.h"
#include "EventListener.h"
#include "ActionBinding.h"
namespace StiUniverse
{

class OptionMenuState :
    public StiGame::Gui::GuiState,
    public StiGame::EventListener
{
    public:
        OptionMenuState();
        virtual ~OptionMenuState();
        void onStart(void);
    protected:
    void saveBindings(void);
    void handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *args);
    StiGame::Gui::KeyBind keyUp;
    StiGame::Gui::KeyBind keyDown;
    StiGame::Gui::KeyBind keyLeft;
    StiGame::Gui::KeyBind keyRight;
    StiGame::Gui::Button btnBack;
    StiGame::Gui::Label lblUp;
    StiGame::Gui::Label lblDown;
    StiGame::Gui::Label lblLeft;
    StiGame::Gui::Label lblRight;
    StiGame::ActionBinding bindings;
    private:
};

}

#endif // OPTIONMENUSTATE_H
