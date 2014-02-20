#ifndef ASSETGENERATOR_H
#define ASSETGENERATOR_H

#include <string>
#include "VarFile.h"

namespace StiGame
{

class AssetGenerator
{
    public:
        AssetGenerator();
        virtual ~AssetGenerator();
        void generateSprite(std::string vf_name);
        void generateDirectionSprite(std::string vf_name);
		void generateGuiResource(std::string vf_gui);
        void generateBindings(void);
    protected:
    private:
};

}

#endif // ASSETGENERATOR_H
