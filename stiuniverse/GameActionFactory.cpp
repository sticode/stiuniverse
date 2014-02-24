#include "GameActionFactory.h"
#include "UnitMovementAction.h"

using namespace StiGame;

namespace StiUniverse{
GameActionFactory::GameActionFactory()
{
    //ctor
}

GameActionFactory::~GameActionFactory()
{
    //dtor
}

void GameActionFactory::MapAction(std::list<BaseGameAction*> actions, ActionBinding *binds)
{
    std::list<BaseGameAction*>::iterator lit(actions.begin()), lend(actions.end());
    for(;lit!=lend;++lit)
    {
        std::string a_name = (*lit)->getName();

        ActionMap *amap = binds->getBinding(a_name);

        if(amap != 0)
        {
            (*lit)->setActionMap(amap);
        }
    }
}

void GameActionFactory::PopulateMovement(std::list<BaseGameAction*>& actions, GameUnit *unit)
{
    //movement
    UnitMovementAction *um_action;

    um_action = new UnitMovementAction("move_up", SD_UP);
    um_action->setUnit(unit);

    actions.push_back(um_action);


    um_action = new UnitMovementAction("move_down", SD_DOWN);
    um_action->setUnit(unit);

    actions.push_back(um_action);


    um_action = new UnitMovementAction("move_left", SD_LEFT);
    um_action->setUnit(unit);

    actions.push_back(um_action);


    um_action = new UnitMovementAction("move_right", SD_RIGHT);
    um_action->setUnit(unit);

    actions.push_back(um_action);

}

}
