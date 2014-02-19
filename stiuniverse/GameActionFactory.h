#ifndef GAMEACTIONFACTORY_H
#define GAMEACTIONFACTORY_H

#include <list>
#include "BaseGameAction.h"
#include "GameUnit.h"
#include "ActionBinding.h"

namespace StiGame{

class GameActionFactory
{
    public:
        GameActionFactory();
        virtual ~GameActionFactory();
        static std::list<BaseGameAction*> PopulateMovement(std::list<BaseGameAction*> actions, GameUnit *unit);
        static void MapAction(std::list<BaseGameAction*> actions, ActionBinding *binds);
    protected:
    private:
};

}

#endif // GAMEACTIONFACTORY_H
