#include "CompActionMap.h"

namespace StiGame
{

CompActionMap::CompActionMap()
{
    //ctor
    name = "composite action";
    inputType = IT_DEFAULT;
}

CompActionMap::CompActionMap(std::string m_name)
{
    //ctor
    name = m_name;
    inputType = IT_DEFAULT;
}

bool CompActionMap::isInput(InputType it)
{
    std::list<ActionMap*>::iterator lit(actions.begin()), lend(actions.end());
    for(;lit!=lend;++lit)
    {
        if((*lit)->isInput(it))
        {
            return true;
        }
    }

    return false;
}

std::string CompActionMap::toString(void)
{
    std::string comp_str = "c";

    std::list<ActionMap*>::iterator lit(actions.begin()), lend(actions.end());
    for(;lit!=lend;++lit)
    {
        std::string a_str = (*lit)->toString();
        a_str += ",";
        comp_str += a_str;
    }

    return comp_str.substr(0, comp_str.size() - 1);
}

bool CompActionMap::inputEquals(InputType it, int input)
{
    std::list<ActionMap*>::iterator lit(actions.begin()), lend(actions.end());
    for(;lit!=lend;++lit)
    {
        if((*lit)->inputEquals(it, input))
        {
            return true;
        }
    }

    return false;
}

void CompActionMap::push(ActionMap *p_map)
{
    p_map->setName(name);
    actions.push_back(p_map);
}

void CompActionMap::remove(ActionMap *r_map)
{
    actions.remove(r_map);
}

CompActionMap::~CompActionMap()
{
    //dtor
}

}
