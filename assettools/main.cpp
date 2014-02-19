#include <iostream>
#include <string>
#include "AssetGenerator.h"

using namespace StiGame;

int main(int argc, char** argv)
{
    std::string option = "empty";
    std::string var1 = "empty";

    for(int i=0; i<argc; i++)
    {
        if(i == 1)
        {
            //option
            option = argv[i];
        }
        else if(i == 2)
        {
            var1 = argv[i];
        }

    }

    AssetGenerator gen = AssetGenerator();

    if(option == "dsprite")
    {
        gen.generateDirectionSprite(var1);
        std::cout << "generating direction sprite : " << var1 << std::endl;
    }
    else if(option == "sprite")
    {
        gen.generateSprite(var1);
        std::cout << "generating sprite : " << var1 << std::endl;
    }
}
