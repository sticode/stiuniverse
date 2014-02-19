#include "GuiRadioButton.h"
#include "RadioGroup.h"

namespace StiGame
{

const int GuiRadioButton::DefaultCaptionOffset = 4;

GuiRadioButton::GuiRadioButton() : GuiItem()
{
    font = style->getNormalFont();
    surfaceEmpty = style->getRadio();
    surfaceChecked = style->getRadioChecked();
    captionOffset = DefaultCaptionOffset;
    checked = false;
    stringBuffer = 0;
    group = 0;
}

void GuiRadioButton::setGroup(RadioGroup *m_group)
{
    group = m_group;
}

void GuiRadioButton::setCaption(std::string m_caption)
{
    caption = m_caption;
    renderCaption();
}

std::string GuiRadioButton::getCaption(void)
{
    return caption;
}

void GuiRadioButton::setChecked(bool m_checked)
{
    checked = m_checked;
}

bool GuiRadioButton::isChecked(void)
{
    return checked;
}

void GuiRadioButton::renderCaption(void)
{
    if(stringBuffer != 0)
    {
        delete stringBuffer;
    }

    stringBuffer = font->renderText(caption, foreground);
    width = stringBuffer->getWidth() + captionOffset + surfaceEmpty->getWidth();
    height = surfaceEmpty->getHeight();
}

void GuiRadioButton::onClick(Point *relp)
{
    //checking if the mouse click was in the radio image

    SRect *radioRect = surfaceEmpty->getSRect(width - surfaceEmpty->getWidth(), 0);

    if(radioRect->contains(relp))
    {
        checked = !checked;
        if(checked)
        {
            if(group != 0)
            {
                group->setActive(this);
            }
        }

        //throw event here
        CheckEventArgs *args = new CheckEventArgs(checked, caption);
        publish(this, args);
        delete args;
    }

}

Surface *GuiRadioButton::render(void)
{
    if(stringBuffer == 0)
    {
        renderCaption();
    }

    Surface *buffer = new Surface(width, height);
    buffer->fill(background);

    //caption drawing

    SDL_Rect *src,*dst;

    src = stringBuffer->getRect();
    dst = stringBuffer->getRect(0, height / 2 - stringBuffer->getHeight()/2);

    buffer->blit(stringBuffer, src, dst);

    delete src;
    delete dst;

    //drawing the image

    Surface *radio_sur;

    if(checked)
    {
        radio_sur = surfaceChecked;
    }
    else
    {
        radio_sur = surfaceEmpty;
    }

    src = radio_sur->getRect();
    dst = radio_sur->getRect(width - radio_sur->getWidth(), 0);

    buffer->blit(radio_sur, src, dst);

    delete src;
    delete dst;

    return buffer;

}

GuiRadioButton::~GuiRadioButton()
{
    //dtor

}

}
