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
		void generateResourceFile(std::string vf_res);
        void generateBindings(void);
    protected:
    private:
};

}

#endif // ASSETGENERATOR_H
