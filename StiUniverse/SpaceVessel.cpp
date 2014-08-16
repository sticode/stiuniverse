#include "SpaceVessel.h"
#include "GamePath.h"
#include "DirectionSpriteFile.h"
using namespace StiGame;

namespace StiUniverse
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
	int diffy = 0;
	int diffx = 0;

    if(( direction & SD_UP ) == SD_UP)
    {
        //y -= speed;
		diffy = -1;
	}

    if( (direction & SD_DOWN) == SD_DOWN )
    {
        //y += speed;
		diffy = 1;
	}

    if( (direction & SD_LEFT) == SD_LEFT)
    {
        //x -= speed;
		diffx = -1;
	}

    if( (direction & SD_RIGHT) == SD_RIGHT)
    {
        //x += speed;
		diffx = 1;
    }

	int dspeed = speed;

	if(diffx != 0 && diffy != 0)
	{
		dspeed = speed / 2;
	}

	x += (dspeed * diffx);
	y += (dspeed * diffy);

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
	maxHp = 0;
	currentHp = 0;
    //mtypes = new MissileType[MISSILE_TYPE_MAX];
}

int SpaceVessel::getMaxHp(void)
{
	return maxHp;
}

int SpaceVessel::getCurrentHp(void)
{
	return currentHp;
}

bool SpaceVessel::isDead(void)
{
	return (currentHp <= 0);
}


void SpaceVessel::spawnVessel(int v_width, int v_height)
{
    /*x = (v_width - width) / 2;
    y = v_height - (height*2);
    sprite->set(x,y);*/
    x = v_width;
    y = v_height;
    sprite->setPoint(x, y);
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

std::string SpaceVessel::getVesselName(void)
{
    return vessel_name;
}

void SpaceVessel::loadSprite(SDL_Renderer *renderer)
{
    //DirectionSpriteFile *sprfile = new DirectionSpriteFile(GamePath::getFilepath(AssetSprite, gfxName + DirectionSpriteFile::FILE_EXTENSION));

    sprite = new DirectionSprite(renderer, GamePath::getFilepath(AssetSprite, "vessel0.dspr").c_str());

    width = sprite->getWidth();
    height = sprite->getHeight();
    //delete sprfile;
}

}
