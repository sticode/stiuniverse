#include "MainMenuState.h"
#include "MainState.h"

namespace StiGame
{

MainMenuState::MainMenuState() : GuiState()
{
    //ctor

    btnStart = Gui::Button();
    btnStart.setCaption("Start game");

    btnStart.subscribe(this);

    btnStart.set(100,100);

    btnQuit = Gui::Button();
    btnQuit.setCaption("Quit");

    btnQuit.subscribe(this);
    btnQuit.set(100,150);

    add(&btnStart);
    add(&btnQuit);
}

void MainMenuState::handleEvent(EventThrower *src, SEventArgs *evt)
{

    if(src == &btnStart)
    {
        MainState *state = new MainState();

        viewport->push(state);
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
