#include "SpaceVessel.h"
#include "GamePath.h"
#include "DirectionSpriteFile.h"
namespace StiGame
{

SpaceVessel::SpaceVessel()
{
    //ctor
    initialize();
}

SpaceVessel::~SpaceVessel()
{
    //dtor
    if(sprite != 0)
    {
        delete sprite;
    }
}

void SpaceVessel::tick(void)
{
    _tick++;
    if(( direction & SD_UP ) == SD_UP)
    {
        y -= speed;
    }

    if( (direction & SD_DOWN) == SD_DOWN )
    {
        y += speed;
    }

    if( (direction & SD_LEFT) == SD_LEFT)
    {
        x -= speed;
    }

    if( (direction & SD_RIGHT) == SD_RIGHT)
    {
        x += speed;
    }
    /*switch(direction)
    {
    case SD_UP:
        y -= speed;
        break;
    case SD_DOWN:
        y += speed;
        break;
    case SD_LEFT:
        x -= speed;
        break;
    case SD_RIGHT:
        x += speed;
        break;
    case SD_IDLE:
        //do nothing
        break;
    }*/

    direction = SD_IDLE;
}

void SpaceVessel::initialize(void)
{
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    speed = 0;
    _tick = 0;
    name = "Space Vessel";
    vessel_name = "";
    gfxName = "";
    direction = SD_IDLE;
    sprite = 0;
    //mtypes = new MissileType[MISSILE_TYPE_MAX];
}


void SpaceVessel::spawnVessel(int v_width, int v_height)
{
    /*x = (v_width - width) / 2;
    y = v_height - (height*2);
    sprite->set(x,y);*/
    x = v_width;
    y = v_height;
    sprite->set(x, y);
}

void SpaceVessel::moveUnit(SDirection m_direction)
{
    direction = (direction | m_direction);
    sprite->setDirection(m_direction);
}

DirectionSprite* SpaceVessel::getSprite(void)
{
    return sprite;
}

BaseMissile* SpaceVessel::throwMissile(int index, SDL_Renderer *renderer, double angle)
{
    if(index >= 0 && index < MISSILE_THROWER_MAX)
    {
        MissileThrower *thrower = mthrowers[index];
        if(thrower->isReady())
        {
            if(thrower->getRenderer() == 0)
            {
                thrower->setRenderer(renderer);
            }

            BaseMissile *missile = thrower->throwMissile(x + (width/2), y + (height/2), angle);

            if(missile != 0)
            {
                return missile;
            }
        }
    }

    return 0;
}

void SpaceVessel::loadSprite(SDL_Renderer *renderer)
{
    DirectionSpriteFile *sprfile = new DirectionSpriteFile(GamePath::getFilepath(AssetSprite, gfxName + DirectionSpriteFile::FILE_EXTENSION));
    sprite = new DirectionSprite(sprfile, renderer);

    width = sprite->getWidth();
    height = sprite->getHeight();
    delete sprfile;
}

}
