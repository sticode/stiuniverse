#pragma once
#include "SDL.h"
#include "SEventArgs.h"
namespace StiGame
{

class EventThrower;
/// \class EventListener
/// \brief Class to implement if you want to be able do handle GuiItem Events
class EventListener
{
public:
    /// \brief Constructor
	EventListener(void);
	/// \brief Destructor
	~EventListener(void);
	/// \brief Method to override to handle your event
	/// \param src Event source
	/// \param evt Event args
	virtual void handleEvent(EventThrower *src, SEventArgs *evt);
};

}

