#include "ObjectField.h"

namespace StiGame
{

namespace Serialization
{

const int ObjectField::UNDEFINED = -1;

ObjectField::ObjectField()
{
	name = ""
	type = UNDEFINED
	length = 0;
}
ObjectField::ObjectField(std::string m_name)
{
	name = m_name
	type = UNDEFINED;
	length = 0;
}

ObjectField::~ObjectField() {}
	
std::string ObjectField::getName(void)
{
	return name;
}
	
int ObjectField::getLength(void)
{
	return length;
}

int ObjectField::getType(void)
{
	return type;
}

void ObjectField::updateMarker(FieldMarker *marker)
{
	marker->dataLength = length;
	marker->nameLength = name.size();
	marker->type = type;
}
	
	//pure virtual
	//virtual char* getData(void) = 0;
	//virtual void setData(char* m_data, int length) = 0;
	
	//members
	//std::string name;
	//int length;
	//int type;

}

}