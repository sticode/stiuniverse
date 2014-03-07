#ifndef COMPACTIONMAP_H
#define COMPACTIONMAP_H

#include "ActionMap.h"
#include <list>

namespace StiGame
{

class CompActionMap :
    public ActionMap
{
    public:
        CompActionMap();
        CompActionMap(std::string m_name);
        virtual ~CompActionMap();
        bool isInput(InputType it);
        bool inputEquals(InputType it, int input); //need a rework on this

        std::string toString(void);
        void push(ActionMap *p_map);
        void remove(ActionMap *r_map);

        int getIntValue(void);
    protected:
        std::list<ActionMap*> actions;
    private:
};

}
#endif // COMPACTIONMAP_H
