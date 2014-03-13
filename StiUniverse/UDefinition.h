#ifndef UDEFINITION_H
#define UDEFINITION_H

#include <string>

namespace StiUniverse
{

namespace Core
{

class UDefinition
{
public:
	static const int UNDEFINED;
	
	UDefinition();
	UDefinition(int m_typeId, std::string m_typeName);
	virtual ~UDefinition();
	
	std::string getTypeName(void);
	int getTypeId(void);
private:
	int typeId;
	std::string typeName;

};

}

}


#endif