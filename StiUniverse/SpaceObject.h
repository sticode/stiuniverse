#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

#include "UObject.h"
#include "MPoint.h"
#include "SpaceMapFile.h"

namespace StiUniverse
{

class SpaceObject : 
	public Core::UObject,
	public StiGame::MPoint
{
public:
	SpaceObject();
	SpaceObject(SpaceObjectType m_objectType);
	virtual ~SpaceObject();

	SpaceObjectType getObjectType(void);
	
protected:
	SpaceObjectType objectType;

private:
	static const int TYPE_ID;
	static const std::string TYPE_NAME;

};


}

#endif