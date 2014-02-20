#ifndef GUIRESOURCEFILE_H
#define GUIRESOURCEFILE_H

#include <string>
#include <map>

#include "Surface.h"

namespace StiGame
{
	const int RESOURCE_NAME_MAX = 64;

	struct ResourceMarker
	{
		char name[RESOURCE_NAME_MAX];
		int length;
	};

	class GuiResourceFile
	{
	public:
		const static std::string FILENAME;
		GuiResourceFile();
		virtual ~GuiResourceFile();
		void addResource(std::string r_name, std::string r_path);
		Surface* getSurface(std::string r_name);
		void save(std::string destination);
		void load(std::string source);
	protected:
		std::map<std::string, Surface*> resources;
		std::map<std::string, std::string> resourcesPath;
	};

}

#endif
