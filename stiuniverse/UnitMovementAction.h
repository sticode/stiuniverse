#ifndef UNITMOVEMENTACTION_H
#define UNITMOVEMENTACTION_H
#include "BaseGameAction.h"
#include "DirectionSprite.h"
#include "GameUnit.h"
namespace StiGame
{


class UnitMovementAction :
    public BaseGameAction
{
    public:
        UnitMovementAction();
        UnitMovementAction(std::string m_name, SDirection m_direction);
        virtual ~UnitMovementAction();
        void setUnit(GameUnit *m_unit);
    protected:
        GameUnit *unit;
        SDirection direction;
        void doAction(void);
    private:
};

}

#endif // UNITMOVEMENTACTION_H
