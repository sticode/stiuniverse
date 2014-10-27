#include "MainMenuState.h"
#include "MainState.h"
#include "OptionMenuState.h"

using namespace StiGame;

namespace StiUniverse
{

MainMenuState::MainMenuState() : GuiState()
{
    //ctor

    btnStart = Gui::Button();
    btnStart.setCaption("Start game");

    btnStart.subscribe(this);

    btnStart.setPoint(100,100);


    btnOption = Gui::Button();
    btnOption.setCaption("Option");

    btnOption.subscribe(this);
    btnOption.setPoint(100,150);

    btnQuit = Gui::Button();
    btnQuit.setCaption("Quit");

    btnQuit.subscribe(this);
    btnQuit.setPoint(100,200);

    add(&btnStart);
    add(&btnOption);
    add(&btnQuit);
}

bool MainMenuState::handleEvent(EventThrower *src, EventArgs *evt)
{

    if(src == &btnStart)
    {
        MainState *state = new MainState();
        viewport->push(state);
    }
    else if (src == &btnOption)
    {
        OptionMenuState *optionState = new OptionMenuState();
        viewport->push(optionState);
    }
    else if(src == &btnQuit)
    {
        running = false;
        return true;
    }

    return false;
}

MainMenuState::~MainMenuState()
{
    //dtor
}

}
