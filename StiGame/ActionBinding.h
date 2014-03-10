#ifndef ACTIONBINDING_H
#define ACTIONBINDING_H

#include "VarFile.h"
#include "ActionMap.h"

namespace StiGame {

class ActionBinding :
    public VarFile
{
    public:
        static const std::string FILENAME;
        ActionBinding();
        ActionBinding(const char* m_filepath);
        void read(void);
        void write(void);
        void addBinding(std::string bname, ActionMap *amap);
		void overwrite(std::string bname, ActionMap *nmap);
        std::string getActionByMouseButton(Uint8 button);
        std::string getActionByKeyCode(SDL_Keycode keycode);
        ActionMap* getBinding(std::string bname);
        virtual ~ActionBinding();
    protected:
        std::map<std::string, ActionMap*> bindings;
    private:
};

}

#endif // ACTIONBINDING_H
