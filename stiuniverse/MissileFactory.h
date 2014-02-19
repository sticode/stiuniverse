#include "BaseMissile.h"

namespace StiGame
{
	enum MissileType { MT_RED, MT_GREEN, MT_BIGORANGE };

	class MissileFactory
	{
	public:
		static BaseMissile* CreateMissile(MissileType mtype, SDL_Renderer *renderer, int m_x, int m_y, double m_angle);
	};
}