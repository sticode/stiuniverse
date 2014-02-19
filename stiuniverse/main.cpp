#include "Viewport.h"
#include <iostream>
#include "MainMenuState.h"
#include "GamePath.h"
#include "DirectionSpriteFileCreator.h"
#include "DirectionSpriteFile.h"
#include "AssetGenerator.h"
#include "ActionBinding.h"
#include "KeyActionMap.h"
#include "MathTK.h"
#include <string>
using namespace StiGame;


int main(int argc, char** argv)
{
    AssetGenerator gen = AssetGenerator();

    gen.generateBindings();

    Viewport *viewport = new Viewport(1000, 650);
    viewport->setResizable(true);
    viewport->setFps(30);

    MainMenuState ms = MainMenuState();

    viewport->push(&ms);
    viewport->setTitle("StiUniverse : just one light year before alpha !");
    viewport->startLoop();

    delete viewport;

    //atexit(SDL_Quit);
    SDL_Quit();
    return 0;
}


