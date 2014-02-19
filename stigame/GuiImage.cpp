
#include "GuiImage.h"
#include "PLine.h"
namespace StiGame
{

GuiImage::GuiImage(void)
{
    imagePath = "";
    imageBuffer = 0;
    drawBorder = false;
}

void GuiImage::setDrawBorder(bool m_drawBorder)
{
    drawBorder = m_drawBorder;
}

void GuiImage::setImage(char* m_imagePath)
{
    imagePath = m_imagePath;
    loadImage();
}

void GuiImage::loadImage(void)
{
    if(imageBuffer != 0)
    {
        delete imageBuffer;
        imageBuffer = 0;
    }

    imageBuffer = new Surface(imagePath);
    width = imageBuffer->getWidth();
    height = imageBuffer->getHeight();
}

Surface* GuiImage::render(void)
{
    if(imageBuffer == 0)
    {
        return new Surface(1,1);
    }

    Surface *buffer = new Surface(imageBuffer->getSDLSurface());
    buffer->setReleaseSurface(false);

    if(drawBorder)
    {
        PLine l1 = PLine();
        PLine l2 = PLine();
        PLine l3 = PLine();
        PLine l4 = PLine();

        l1.set1(0, 0);
        l1.set2(width - 1, 0);

        l2.set1(0, 0);
        l2.set2(0, height - 1);

        l3.set1(width - 1, 0);
        l3.set2(width - 1, height - 1);

        l4.set1(0, height - 1);
        l4.set2(width - 1, height - 1);

        buffer->draw(&l1, foreground);
        buffer->draw(&l2, foreground);
        buffer->draw(&l3, foreground);
        buffer->draw(&l4, foreground);
    }

    return buffer;
}

void GuiImage::setAlpha(int n_alpha)
{
    if(imageBuffer != 0)
    {
        imageBuffer->setTransparentColor(0,0,0);
        imageBuffer->setAlpha(n_alpha);
    }
}

GuiImage::~GuiImage(void)
{
}

}
