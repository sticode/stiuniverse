#ifndef MOUSEBUTTONEVENT_H
#define MOUSEBUTTONEVENT_H

#include "EventArgs.h"

namespace StiGame
{

class MouseButtonEvent
    : public EventArgs
{
    public:
        MouseButtonEvent();
        MouseButtonEvent(SDL_Event *m_sdlEvent);
        virtual ~MouseButtonEvent();

        Sint32 getX(void);
        Sint32 getY(void);

        Uint8 getButton(void);
        Uint32 getWindowID(void);

        bool isDown(void);

    protected:
    private:
};

}
#endif // MOUSEBUTTONEVENT_H