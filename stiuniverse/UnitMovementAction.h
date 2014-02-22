#ifndef UNITMOVEMENTACTION_H
#define UNITMOVEMENTACTION_H
#include "BaseGameAction.h"
#include "DirectionSprite.h"
#include "GameUnit.h"
namespace StiUniverse
{


class UnitMovementAction :
    public StiGame::BaseGameAction
{
    public:
        UnitMovementAction();
        UnitMovementAction(std::string m_name, StiGame::SDirection m_direction);
        virtual ~UnitMovementAction();
        void setUnit(StiGame::GameUnit *m_unit);
    protected:
        StiGame::GameUnit *unit;
        StiGame::SDirection direction;
        void doAction(void);
    private:
};

}

#endif // UNITMOVEMENTACTION_H
