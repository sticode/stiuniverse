#include "MultiRect.h"
#include <iostream>
namespace StiGame
{

MultiRect::MultiRect()
{
    //ctor
}

void MultiRect::clear(void)
{
    std::list<SRect*>::iterator lit(rects.begin()), lend(rects.end());
    for(;lit!=lend;++lit)
    {
        delete (*lit);
    }

    rects.clear();
}

bool MultiRect::contains(Point *pt)
{
    return contains(pt->getX(), pt->getY());
}

bool MultiRect::contains(ISprite *sprite)
{
    //need to rework this ! ASAP
    bool contain_sprite = false;

    SRect *tmp_rect = new SRect(sprite->getX(), sprite->getY(), sprite->getWidth(), sprite->getHeight());

    std::list<SRect*>::iterator lit(rects.begin()), lend(rects.end());
    for(;lit!=lend;++lit)
    {
        if( (*lit)->intersect(tmp_rect)
           )
        {
            contain_sprite = true;
            break;
        }
    }

    delete tmp_rect;

    return contain_sprite;
}

bool MultiRect::contains(int p_x, int p_y)
{
    std::list<SRect*>::iterator lit(rects.begin()), lend(rects.end());
    for(;lit!=lend;++lit)
    {
        if( (*lit)->contains(p_x, p_y) )
        {
            return true;
        }
    }

    return false;
}

void MultiRect::addRect(SRect *rect)
{
    rects.push_back(rect);
}

void MultiRect::addRect(int r_x, int r_y, int r_w, int r_h)
{
    rects.push_back(new SRect(r_x, r_y, r_w, r_h));
}

MultiRect::~MultiRect()
{
    //dtor
}

}
