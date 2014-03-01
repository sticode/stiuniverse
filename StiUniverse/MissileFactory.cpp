#include "MissileFactory.h"
#include "BigOrangeMissile.h"
#include "GreenMissile.h"
#include "RedMissile.h"

using namespace StiGame;

namespace StiUniverse
{
	BaseMissile* MissileFactory::CreateMissile(MissileType mtype, SDL_Renderer *renderer, int m_x, int m_y, double m_angle)
	{
		BaseMissile *missile = 0;

		switch(mtype)
		{
		case MT_RED:
			missile = new RedMissile(renderer, m_x, m_y, m_angle);
			break;
		case MT_GREEN:
			missile = new GreenMissile(renderer, m_x, m_y, m_angle);
			break;
		case MT_BIGORANGE:
			missile = new BigOrangeMissile(renderer, m_x, m_y, m_angle);
			break;
		}

		return missile;
	}

}
