#include "RadioGroup.h"

namespace StiGame {

RadioGroup::RadioGroup()
{
    //ctor
    active = 0;
}

void RadioGroup::addItem(GuiRadioButton *radio)
{
    radioButtons.push_back(radio);
    radio->setGroup(this);
}

void RadioGroup::removeItem(GuiRadioButton *radio)
{
    radioButtons.remove(radio);
}

void RadioGroup::setActive(GuiRadioButton *radio)
{
    std::list<GuiRadioButton*>::iterator lit(radioButtons.begin()), lend(radioButtons.end());
    active = radio;
    for(; lit!=lend; ++lit)
    {
        if((*lit)!=radio)
        {
            if((*lit)->isChecked())
            {
                (*lit)->setChecked(false);
            }
        }
        else
        {
            if(!(*lit)->isChecked())
            {
                (*lit)->setChecked(true);
            }
        }
    }
}

GuiRadioButton *RadioGroup::getActive(void)
{
    return active;
}

RadioGroup::~RadioGroup()
{
    //dtor
}

}
