#include "UnitMovementAction.h"
namespace StiGame
{
UnitMovementAction::UnitMovementAction()
{
    //ctor
    name = "";
    unit = 0;
}

UnitMovementAction::UnitMovementAction(std::string m_name, SDirection m_direction)
{
    name = m_name;
    direction = m_direction;
    unit = 0;
}

void UnitMovementAction::setUnit(GameUnit *m_unit)
{
    unit = m_unit;
}

void UnitMovementAction::doAction(void)
{
    if(unit != 0)
    {
        unit->moveUnit(direction);
    }
}

UnitMovementAction::~UnitMovementAction()
{
    //dtor
}
}
