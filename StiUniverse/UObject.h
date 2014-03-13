#ifndef UOBJECT_H
#define UOBJECT_H

#include "UDefinition.h"

namespace StiUniverse
{

namespace Core
{

//StiUniverse super-class
class UObject
{
public:
	int getTypeId(void);
	std::string getTypeName(void);
	UDefinition getDefinition(void);
	bool sameDef(UObject *obj);
	UObject* toBase(void);
protected:
	UObject();
	UObject(int typeId, std::string typeName);
	
	virtual ~UObject();
private:
	UDefinition definition;
};

}

}

#endif