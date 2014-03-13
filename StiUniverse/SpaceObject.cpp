#include "SpaceObject.h"


namespace StiUniverse
{

const int SpaceObject::TYPE_ID = 1;
const std::string SpaceObject::TYPE_NAME = "SpaceObject";

SpaceObject::SpaceObject() :
	Core::UObject(TYPE_ID, TYPE_NAME),
	StiGame::MPoint()
{
	objectType = SOT_ASTEROID;
}

SpaceObject::SpaceObject(SpaceObjectType m_objectType) :
	Core::UObject(TYPE_ID, TYPE_NAME),
	StiGame::MPoint()
{
	objectType = m_objectType;
}

SpaceObjectType SpaceObject::getObjectType(void)
{
	return objectType;
}

SpaceObject::~SpaceObject()
{

}

}