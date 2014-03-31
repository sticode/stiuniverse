
#include "Viewport.h"
#include "Runtime.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "Sprite.h"
#include <iostream>
#include <string>
#include <ctime>
#include "Time.h"
namespace StiGame
{

Viewport::Viewport(void)
{
    centered = true;
	error = "";
	msWaitTime = 0;
	screen = 0;
	window = 0;
	sdlWindow = 0;
	width = 640;
	height = 480;
	fullscreen = false;
	title = "StiGame::Viewport";
	initialize();
}

Viewport::Viewport(int v_width, int v_height)
{
    centered = true;
	resizable = true;
	error = "";
	msWaitTime = 0;
	screen = 0;
	window = 0;
	sdlWindow = 0;
	width = v_width;
	height = v_height;
	fullscreen = false;
	title = "StiGame::Viewport";
	initialize();
}


Viewport::Viewport(int v_width, int v_height, bool v_fullscreen)
{
    centered = true;
	resizable = true;
	error = "";
	msWaitTime = 0;
	screen = 0;
	sdlWindow = 0;
	window = 0;
	width = v_width;
	height = v_height;
	fullscreen = v_fullscreen;
	title = "StiGame::Viewport";
	initialize();
}

bool Viewport::getResizable(void)
{
	return resizable;
}

void Viewport::setResizable(bool m_resizable)
{
	resizable = m_resizable;
}

void Viewport::resize(int m_width, int m_height)
{
	if(resizable && !fullscreen)
	{
		width = m_width;
		height = m_height;

        //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        //SDL_RenderSetLogicalSize(renderer, width, height);
        /** \brief
         *
         * \param width
         * \param height
         * \param 32
         * \param videoFlags
         * \return screen=
         *
         */
		//screen = SDL_SetVideoMode(width, height, 32, videoFlags);
        //area.setViewDimension(width, height);
		if(currentState != 0)
		{
			currentState->onResize(width, height);
		}
	}
}

void Viewport::handleWindowEvent(SDL_Event *evt)
{
    switch(evt->window.event)
    {
        case SDL_WINDOWEVENT_RESIZED:
            resize(evt->window.data1, evt->window.data2);
            break;
        case SDL_WINDOWEVENT_MOVED:
            updateWindowPosition();
            break;
    }
	
	WindowEventArgs wargs = WindowEventArgs(evt);
	publish(this, &wargs);

}

void Viewport::tick(void)
{
	//checking event
    Sprite::tickSprites();

	SDL_Event evt;

	while(SDL_PollEvent(&evt))
	{
		switch(evt.type)
		{
		    //temporary need to let the state choose
			case SDL_QUIT:

			    if(currentState->isHandleQuit())
                {
                    currentState->onEvent(&evt);
                }
                else
                {
                    run = false;
                }

				break;
            case SDL_WINDOWEVENT:
                handleWindowEvent(&evt);
                break;

			default:
				currentState->onEvent(&evt);
				break;
		}
	}

	if(!currentState->isRunning())
	{
		run = false;
	}
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	currentState->onPaint(renderer);

	SDL_RenderPresent(renderer);
	//int rs = SDL_Flip(screen);
}

void Viewport::startLoop(void)
{
	if(currentState != 0)
	{
		run = true;
		while(run)
		{
			//starting tick

			unsigned long long diff = Time::GetMsTimestamp() - lastTick;

			if(diff >= msWaitTime)
			{
                unsigned long long over = diff - msWaitTime;

                if(over != 0)
                {
                    std::cout << "missed frame by " << over << "ms !" << std::endl;
                }
				tick();
				lastTick = Time::GetMsTimestamp();
			}

			//ending time
			//SDL_Delay(diff);
			SDL_Delay(1);
		}

		//quitting, unloading
		currentState->unload();
		//quick hack
		Gui::Runtime::getInstance()->getStyle()->unload();
	}
}

void Viewport::push(BaseGameState* state)
{
	if(state != 0)
	{
	    if(currentState != 0)
        {
            currentState->unload();
        }

		currentState = state;
		currentState->setViewport((Viewport*)this);
		currentState->onResize(width, height);
		currentState->onStart();
	}
}

SDL_Rect* Viewport::getLowestMode(void)
{
	SDL_Rect* rect = new SDL_Rect();
	rect->h = 1080;
	rect->w = 1920;

	std::list<Dimension*>::iterator lit (modes.begin()), lend(modes.end());

	for(;lit!=lend;++lit)
	{
        if((*lit)->getHeight() < rect->h && (*lit)->getWidth() < rect->w)
        {
            rect->h = (*lit)->getHeight();
            rect->w = (*lit)->getWidth();
        }
	}

	return rect;
}

SDL_Rect* Viewport::getHighestMode(void)
{
	SDL_Rect* rect = new SDL_Rect();
	rect->h = 0;
	rect->w = 0;

	std::list<Dimension*>::iterator lit (modes.begin()), lend(modes.end());

	for(;lit!=lend;++lit)
	{
        if((*lit)->getHeight() > rect->h && (*lit)->getWidth() > rect->w)
        {
            rect->h = (*lit)->getHeight();
            rect->w = (*lit)->getWidth();
        }
	}

	return rect;
}

void Viewport::setFps(int fps)
{
	target_fps = fps;
	msWaitTime = CLOCKS_PER_SEC / fps;
}

int Viewport::getFps(void)
{
	return target_fps;
}

void Viewport::initialize(void)
{
    window_x = SDL_WINDOWPOS_UNDEFINED;
    window_y = SDL_WINDOWPOS_UNDEFINED;

    //area = ViewportArea();

	lastTick = 0;
	run = false;
	currentState = 0;
	SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
	TTF_Init();

	listDimensions();

	SDL_Rect* hsize = getHighestMode();

	if(hsize->w < width || hsize->h < height)
	{
		width = hsize->w;
		height = hsize->h;
		std::cout << "Overriding resolution to " << width << "x" << height;
	}

    videoFlags = 0;

	if(fullscreen)
	{
		resizable = false;
		videoFlags =  videoFlags | SDL_WINDOW_FULLSCREEN;
	}
	else if(resizable)
	{
		videoFlags =  videoFlags | SDL_WINDOW_RESIZABLE;
	}

    if(centered)
    {
        window_x = SDL_WINDOWPOS_CENTERED;
        window_y = SDL_WINDOWPOS_CENTERED;
    }

	sdlWindow = SDL_CreateWindow(title, window_x, window_y, width, height, videoFlags);
	window = new Window(sdlWindow);
    renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
    cursor = new Cursor();
    SDL_SetWindowTitle(sdlWindow, title);

    updateWindowPosition();

    //area.setViewPoint(0,0);
    //area.setViewDimension(width, height);

    //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    //SDL_RenderSetLogicalSize(renderer, width, height);

	error = SDL_GetError();
}

Cursor* Viewport::getCursor(void)
{
    return cursor;
}

void Viewport::showCursor(bool m_show)
{
    Cursor::Show(m_show);
}

void Viewport::setCursor(Cursor *m_cursor)
{
    if(!cursor->isDefault())
    {
        delete cursor;
    }

    cursor = m_cursor;
    SDL_SetCursor(cursor->getSDLCursor());
}

bool Viewport::isFullscreen(void)
{
	return fullscreen;
}


Viewport::~Viewport(void)
{
    if(sdlWindow != 0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(sdlWindow);
    }
}

int Viewport::getHeight(void)
{
    return height;
}
int Viewport::getWidth(void)
{
    return width;
}

void Viewport::setTitle(const char* m_title)
{
    title = m_title;
    if(sdlWindow != 0)
    {
        SDL_SetWindowTitle(sdlWindow, title);
    }
}

const char* Viewport::getTitle(void)
{
    return title;
}

void Viewport::listDimensions()
{
    //need to do some work here, multi-display mmokay
    int nb = SDL_GetNumDisplayModes(0);

    for(int i=0; i<nb; i++)
    {
        SDL_DisplayMode mode = SDL_DisplayMode();
        SDL_GetDisplayMode(0, i, &mode);

        Dimension *dim = new Dimension(mode.w, mode.h);

        if(!isModePresent(dim))
        {
            modes.push_back(dim);
        }
        else
        {
            delete dim;
        }
    }
}

bool Viewport::isModePresent(Dimension *dimension)
{
    std::list<Dimension*>::iterator lit(modes.begin()), lend(modes.end());

    for(;lit!=lend;++lit)
    {
        if((*lit)->getHeight() == dimension->getHeight() &&
           (*lit)->getWidth() == dimension->getWidth() )
        {
            return true;
        }
    }

    return false;
}

int Viewport::getWindowX(void)
{
    return window_x;
}

int Viewport::getWindowY(void)
{
    return window_y;
}

void Viewport::setWindowPosition(int m_window_x, int m_window_y)
{
    window_x = m_window_x;
    window_y = m_window_y;

    SDL_SetWindowPosition(sdlWindow, window_x, window_y);
}

void Viewport::updateWindowPosition(void)
{
    int m_window_x, m_window_y;

    SDL_GetWindowPosition(sdlWindow, &m_window_x, &m_window_y);

    window_x = m_window_x;
    window_y = m_window_y;
}

void Viewport::setGrab(bool grab)
{
    if(grab)
    {
        SDL_SetWindowGrab(sdlWindow, SDL_TRUE);
    }
    else
    {
        SDL_SetWindowGrab(sdlWindow, SDL_FALSE);
    }
}

bool Viewport::isGrabbed(void)
{
	SDL_bool grabbed = SDL_GetWindowGrab(sdlWindow);

	return (grabbed == SDL_TRUE);
}

SDL_Window* Viewport::getSDLWindow(void)
{
    return sdlWindow;
}

Window* Viewport::getWindow(void)
{
	return window;
}

SDL_Renderer* Viewport::getRenderer(void)
{
    return renderer;
}

void Viewport::show(void)
{
	if(sdlWindow != 0)
	{
		SDL_ShowWindow(sdlWindow);
	}
}

void Viewport::hide(void)
{
	/*if(sdlWindow != 0)
	{
		SDL_HideWindow(sdlWindow);
	}*/
	window->hide();
}

void Viewport::restore(void)
{
	/*if(sdlWindow != 0)
	{
		SDL_RestoreWindow(sdlWindow);
	}*/
	window->restore();
}

void Viewport::minimize(void)
{
	/*if(sdlWindow != 0)
	{
		SDL_MinimizeWindow(sdlWindow);
	}*/
	window->minimize();
}

void Viewport::maximize(void)
{
	/*if(sdlWindow != 0)
	{
		SDL_MaximizeWindow(sdlWindow);
	}*/
	window->maximize();
}


}
