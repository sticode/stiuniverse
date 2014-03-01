#ifndef SPACEMAPFILE_H
#define SPACEMAPFILE_H

#include <string>
#include <vector>

namespace StiUniverse
{

const int MAP_NAME_MAX = 64;
const int MAP_OBJ_NAME_MAX = 64;

enum SpaceObjectType { SOT_ASTEROID, SOT_PLANET, SOT_SHIP };

struct SpaceMapHeader
{
	int width;
	int height;
	char mapName[MAP_NAME_MAX];
	int nbObjects;
};

struct SpaceObjectStruct
{
	int x;
	int y;
	int width;
	int height;
	char objName[MAP_OBJ_NAME_MAX];
	SpaceObjectType type;
};


class SpaceMapFile
{
    public:
        SpaceMapFile();
        virtual ~SpaceMapFile();

		//Accessors
		int getWidth(void);
		int getHeight(void);
		int getNbObjects(void);
		std::string getName(void);
		SpaceObjectStruct getSpaceObject(int index);

		//Mutators
		void setWidth(int m_width);
		void setHeight(int m_height);
		void setName(std::string m_name);

		void addSpaceObject(SpaceObjectStruct obj);

		//Serialization method

		void save(std::string path);
		void read(std::string path);

    protected:
		int width;
		int height;
		int nbObjects;
		std::string mapName;
		std::vector<SpaceObjectStruct> objects;

    private:
};

}

#endif // SPACEMAPFILE_H
