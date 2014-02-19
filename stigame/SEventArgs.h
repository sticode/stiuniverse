#pragma once
#include "SDL.h"
namespace StiGame
{
/// \class SEventArgs
/// \brief Basic Event wrapper
class SEventArgs
{
public:
	/// \brief Create an empty event
	SEventArgs(void);
	/// \brief Create an event
	/// \param m_sdlEvent SDL_Event
	SEventArgs(SDL_Event *m_sdlEvent);
	/// \brief SEventArgs destructor
	virtual ~SEventArgs(void);
	/// \brief Get SDL_Event
	/// \return SDL_Event pointer
	SDL_Event *getSDLEvent(void);
protected:
	/// \brief SDL_Event
	SDL_Event *sdlEvent;
};

}