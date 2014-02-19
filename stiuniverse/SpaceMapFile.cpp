#include "SpaceMapFile.h"
#include <iostream>
#include <fstream>
#include <cstring>

namespace StiGame
{

SpaceMapFile::SpaceMapFile()
{
    //ctor
	mapName = "no name";
	width = 0;
	height = 0;
	nbObjects = 0;
}

int SpaceMapFile::getWidth(void)
{
	return width;
}

int SpaceMapFile::getHeight(void)
{
	return height;
}

int SpaceMapFile::getNbObjects(void)
{
	return nbObjects;
}

std::string SpaceMapFile::getName(void)
{
	return mapName;
}

SpaceObjectStruct SpaceMapFile::getSpaceObject(int index)
{
	return objects[index];
}

//Mutators
void SpaceMapFile::setWidth(int m_width)
{
	width = m_width;
}

void SpaceMapFile::setHeight(int m_height)
{
	height = m_height;
}

void SpaceMapFile::setName(std::string m_name)
{
	mapName = m_name;
}

void SpaceMapFile::addSpaceObject(SpaceObjectStruct obj)
{
	objects.push_back(obj);
	nbObjects++;
}

//Serialization method

void SpaceMapFile::save(std::string path)
{
	SpaceMapHeader header = SpaceMapHeader();
	header.mapName[mapName.size()] = 0;
	memcpy(header.mapName, mapName.c_str(), mapName.size());

	header.nbObjects = nbObjects;
	header.width = width;
	header.height = height;

	std::ofstream of (path.c_str(), std::ofstream::binary);

	of.write(reinterpret_cast<char*>(&header), sizeof(SpaceMapHeader));

	std::vector<SpaceObjectStruct>::iterator lit(objects.begin()), lend(objects.end());
	for(;lit!=lend;++lit)
	{
		SpaceObjectStruct obj = (*lit);

		of.write(reinterpret_cast<char*>(&obj), sizeof(SpaceObjectStruct));

	}

	of.close();

}

void SpaceMapFile::read(std::string path)
{
	SpaceMapHeader header;
	SpaceObjectStruct obj;

	std::ifstream is (path.c_str(), std::ifstream::binary);

	is.read((char*)&header, sizeof(SpaceMapHeader));

	nbObjects = header.nbObjects;
	mapName = header.mapName;
	width = header.width;
	height = header.height;

	for(int i=0; i<nbObjects; i++)
	{
		is.read((char*)&obj, sizeof(SpaceObjectStruct));

		objects.push_back(obj);
	}

	is.close();
}

SpaceMapFile::~SpaceMapFile()
{
    //dtor
}


}
