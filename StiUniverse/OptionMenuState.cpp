#include "OptionMenuState.h"
#include "MainMenuState.h"
using namespace StiGame;

namespace StiUniverse
{


OptionMenuState::OptionMenuState() : GuiState()
{
    //ctor
    btnBack = Gui::Button();
    btnBack.setCaption("Back");
    btnBack.setX(400);
    btnBack.setY(600);

    btnBack.subscribe(this);

    add(&btnBack);
}

void OptionMenuState::handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *args)
{
    if(src == &btnBack)
    {
        viewport->push(new MainMenuState());
    }
}

OptionMenuState::~OptionMenuState()
{
    //dtor
}

}
