#ifndef GAMEACTIONFACTORY_H
#define GAMEACTIONFACTORY_H

#include <list>
#include "BaseGameAction.h"
#include "GameUnit.h"
#include "ActionBinding.h"

namespace StiUniverse{

class GameActionFactory
{
    public:
        GameActionFactory();
        virtual ~GameActionFactory();
        static std::list<StiGame::BaseGameAction*> PopulateMovement(std::list<StiGame::BaseGameAction*> actions, StiGame::GameUnit *unit);
        static void MapAction(std::list<StiGame::BaseGameAction*> actions, StiGame::ActionBinding *binds);
    protected:
    private:
};

}

#endif // GAMEACTIONFACTORY_H
