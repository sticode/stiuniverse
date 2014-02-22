#include "BaseMissile.h"

namespace StiUniverse
{
	enum MissileType { MT_RED, MT_GREEN, MT_BIGORANGE };

	class MissileFactory
	{
	public:
		static StiGame::BaseMissile* CreateMissile(MissileType mtype, SDL_Renderer *renderer, int m_x, int m_y, double m_angle);
	};
}
