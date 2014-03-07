#include "MainMenuState.h"
#include "MainState.h"

using namespace StiGame;

namespace StiUniverse
{

MainMenuState::MainMenuState() : GuiState()
{
    //ctor

    btnStart = Gui::Button();
    btnStart.setCaption("Start game");

    btnStart.subscribe(this);

    btnStart.set(100,100);


    btnOption = Gui::Button();
    btnOption.setCaption("Option");

    btnOption.subscribe(this);
    btnOption.set(100,150);

    btnQuit = Gui::Button();
    btnQuit.setCaption("Quit");

    btnQuit.subscribe(this);
    btnQuit.set(100,200);

    add(&btnStart);
    add(&btnOption);
    add(&btnQuit);
}

void MainMenuState::handleEvent(EventThrower *src, EventArgs *evt)
{

    if(src == &btnStart)
    {
        MainState *state = new MainState();
        viewport->push(state);
    }
    else if (src == &btnOption)
    {

    }
    else if(src == &btnQuit)
    {
        running = false;
    }
}

MainMenuState::~MainMenuState()
{
    //dtor
}

}
