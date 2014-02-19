#include "GameOverlay.h"
#include <iostream>
namespace StiGame
{

GameOverlay::GameOverlay() : GuiOverlay()
{
    //ctor
    state = 0;

    resumeButton = GuiButton();
    resumeButton.setCaption("Resume");

    quitButton = GuiButton();
    quitButton.setCaption("Quit");

    resumeButton.subscribe(this);
    quitButton.subscribe(this);

    add(&resumeButton);
    add(&quitButton);

    std::cout << "Game overlay ctr" << std::endl;
}

void GameOverlay::handleEvent(EventThrower *src, SEventArgs *evt)
{
    if(src == &resumeButton)
    {
        visible = false;
    }
    else if(src == &quitButton)
    {
        state->closeGameMenu();
    }
}

void GameOverlay::setState(MainState *m_state)
{
    state = m_state;
}

GameOverlay::~GameOverlay()
{
    //dtor
}

}
