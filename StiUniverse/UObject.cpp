#include "UObject.h"

namespace StiUniverse
{

namespace Core
{


int UObject::getTypeId(void)
{
	return definition.getTypeId();
}

std::string UObject::getTypeName(void)
{
	return definition.getTypeName();
}

UDefinition UObject::getDefinition(void)
{
	return definition;
}

bool UObject::sameDef(UObject *obj)
{
	return (obj->getTypeId() == definition.getTypeId());
}

UObject* UObject::toBase(void)
{
	return dynamic_cast<UObject*>(this);
}


UObject::UObject()
{
	definition = UDefinition();
}

UObject::UObject(int typeId, std::string typeName)
{
	definition = UDefinition(typeId, typeName);
}

UObject::~UObject() { }

}

}
