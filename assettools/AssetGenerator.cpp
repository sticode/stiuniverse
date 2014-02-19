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

void AssetGenerator::generateSprite(std::string vf_name)
{
    std::string vf_path = GamePath::getFilepath(AssetSprite, vf_name + Sprite::FILE_EXTENSION);

    VarFile vf = VarFile(vf_path.c_str());
    vf.read();
    int i = 0;
    int fr_count = 0;
    std::string _base = "sprite";

    std::list<std::string> fr_paths;

    while(true)
    {
        std::string fr_name = _base + ISprite::toString(i);

        if(vf.isVarExists(fr_name))
        {
            std::string fr_path = vf.getValue(fr_name);
            fr_paths.push_back(fr_path);
            fr_count++;
        }
        else
        {
            break;
        }

        i++;
    }

    //generating sprite file
    SpriteFileCreator sfc = SpriteFileCreator();

    sfc.setName(vf_name);

    std::list<std::string>::iterator lit(fr_paths.begin()), lend(fr_paths.end());

    for(;lit!=lend;++lit)
    {
        sfc.addFrame(GamePath::getFilepath(AssetRoot, (*lit)));
    }

    sfc.save(GamePath::getFilepath(AssetSprite, vf_name + SpriteFile::FILE_EXTENSION));
}

void AssetGenerator::generateDirectionSprite(std::string vf_name)
{
    std::string vf_path = GamePath::getFilepath(AssetSprite, vf_name + DirectionSprite::FILE_EXTENSION);
    VarFile vf = VarFile(vf_path.c_str());
    vf.read();

    DirectionSpriteFileCreator dsfc = DirectionSpriteFileCreator();
    dsfc.setName(vf_name);

    int i = 0;
    std::string _base = "up";
    //up
    while(true)
    {
        std::string fr_name = _base + ISprite::toString(i);

        if(vf.isVarExists(fr_name))
        {
            std::string fr_path = vf.getValue(fr_name);
            dsfc.addFrame(SD_UP, GamePath::getFilepath(AssetRoot, fr_path));
        }
        else
        {
            break;
        }

        i++;
    }
    //down
    i = 0;
    _base = "down";
    while(true)
    {
        std::string fr_name = _base + ISprite::toString(i);

        if(vf.isVarExists(fr_name))
        {
            std::string fr_path = vf.getValue(fr_name);
            dsfc.addFrame(SD_DOWN, GamePath::getFilepath(AssetRoot, fr_path));
        }
        else
        {
            break;
        }

        i++;
    }
    //left
    i = 0;
    _base = "left";
    while(true)
    {
        std::string fr_name = _base + ISprite::toString(i);

        if(vf.isVarExists(fr_name))
        {
            std::string fr_path = vf.getValue(fr_name);
            dsfc.addFrame(SD_LEFT, GamePath::getFilepath(AssetRoot, fr_path));
        }
        else
        {
            break;
        }

        i++;
    }
    //right
    i = 0;
    _base = "right";
    while(true)
    {
        std::string fr_name = _base + ISprite::toString(i);

        if(vf.isVarExists(fr_name))
        {
            std::string fr_path = vf.getValue(fr_name);
            dsfc.addFrame(SD_RIGHT, GamePath::getFilepath(AssetRoot, fr_path));
        }
        else
        {
            break;
        }

        i++;
    }
    //idle
    i = 0;
    _base = "idle";
    while(true)
    {
        std::string fr_name = _base + ISprite::toString(i);

        if(vf.isVarExists(fr_name))
        {
            std::string fr_path = vf.getValue(fr_name);
            dsfc.addFrame(SD_IDLE, GamePath::getFilepath(AssetRoot, fr_path));
        }
        else
        {
            break;
        }

        i++;
    }


    //saving
    dsfc.save(GamePath::getFilepath(AssetSprite, vf_name + DirectionSpriteFile::FILE_EXTENSION));
}

}
