#ifndef FIELDRESOLVER_H
#define FIELDRESOLVER_H

#include "ObjectField.h"

namespace StiGame
{

namespace Serialization
{

class FieldResolver
{
public:
	virtual ObjectField* createField(int type, std::string name, char* data, int length) = 0;
protected:
	FieldResolver();
	virtual ~FieldResolver();
};

}

}

#endif