
#include "SEventArgs.h"

namespace StiGame
{

SEventArgs::SEventArgs(void)
{
	sdlEvent = 0;
}

SEventArgs::SEventArgs(SDL_Event *m_sdlEvent)
{
	sdlEvent = m_sdlEvent;
}

SDL_Event *SEventArgs::getSDLEvent(void)
{
	return sdlEvent;
}

SEventArgs::~SEventArgs(void)
{
}

}
