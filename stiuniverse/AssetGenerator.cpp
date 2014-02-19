#include "AssetGenerator.h"
#include "ISprite.h"
#include <list>
#include "SpriteFileCreator.h"
#include "Sprite.h"
#include "DirectionSprite.h"
#include "DirectionSpriteFile.h"
#include "DirectionSpriteFileCreator.h"
#include "GamePath.h"
#include "ActionBinding.h"
#include "KeyActionMap.h"
#include "MouseActionMap.h"
#include "CompActionMap.h"
#include <iostream>

namespace StiGame
{

AssetGenerator::AssetGenerator()
{
    //ctor
}

AssetGenerator::~AssetGenerator()
{
    //dtor
}

void AssetGenerator::generateBindings(void)
{
    ActionBinding binds (ActionBinding::FILENAME.c_str());
    std::list<ActionMap*> actions;
    KeyActionMap *k_map;
    MouseActionMap *m_map;
    CompActionMap *c_map;

    k_map = new KeyActionMap("move_up");
    k_map->setKeycode(SDLK_w);

    actions.push_back(k_map);

    k_map = new KeyActionMap("move_down");
    k_map->setKeycode(SDLK_s);

    actions.push_back(k_map);

    k_map = new KeyActionMap("move_left");
    k_map->setKeycode(SDLK_a);

    actions.push_back(k_map);

    k_map = new KeyActionMap("move_right");
    k_map->setKeycode(SDLK_d);

    actions.push_back(k_map);

    m_map = new MouseActionMap("throw_missile1");
    m_map->setButton(SDL_BUTTON_LEFT);

    actions.push_back(m_map);

    m_map = new MouseActionMap("throw_missile2");
    m_map->setButton(SDL_BUTTON_RIGHT);

    actions.push_back(m_map);

    m_map = new MouseActionMap("throw_missile3");
    m_map->setButton(SDL_BUTTON_MIDDLE);

    actions.push_back(m_map);

    c_map = new CompActionMap();
    c_map->setName("test_compo");

    k_map = new KeyActionMap("allo");
    k_map->setKeycode(SDLK_AC_BACK);

    c_map->push(k_map);

    m_map = new MouseActionMap("allo2");
    m_map->setButton(SDL_BUTTON_LEFT);

    c_map->push(m_map);

    actions.push_back(c_map);

    std::list<ActionMap*>::iterator lit(actions.begin()), lend(actions.end());
    for(;lit!=lend;++lit)
    {
        binds.addBinding((*lit)->getName(), (*lit));
    }

    binds.write();


}


}
