#include "UDefinition.h"

namespace StiUniverse
{

namespace Core
{

const int UDefinition::UNDEFINED = -1;

UDefinition::UDefinition()
{
	typeId = UNDEFINED;
	typeName = "UNDEFINED";
}

UDefinition::UDefinition(int m_typeId, std::string m_typeName)
{
	typeId = m_typeId;
	typeName = m_typeName;
}

UDefinition::~UDefinition() {}
	
std::string UDefinition::getTypeName(void) { return typeName; }
int UDefinition::getTypeId(void) { return typeId; }


}

}
