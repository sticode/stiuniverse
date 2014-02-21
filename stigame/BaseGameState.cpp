
#include "BaseGameState.h"
#include "Viewport.h"
#include "Texture.h"
#include <iostream>

namespace StiGame
{


BaseGameState::BaseGameState(void)
{
    handleQuit = true;
	width = 0;
	height = 0;
	running = false;
	viewport = 0;
	gameMenu = 0;
}

void BaseGameState::setViewport(Viewport *m_viewport)
{
	viewport = m_viewport;
}

Viewport * BaseGameState::getViewport(void)
{
	return viewport;
}

void BaseGameState::setGameMenu(Gui::OverlayMenu *m_gameMenu)
{
	gameMenu = m_gameMenu;
}

Gui::OverlayMenu* BaseGameState::getGameMenu(void)
{
	return gameMenu;
}

bool BaseGameState::isRunning(void)
{
	return running;
}

void BaseGameState::onStart(void)
{

}

void BaseGameState::onResize(int n_width, int n_height)
{
	width = n_width;
	height = n_height;

	if(gameMenu != 0)
	{
		gameMenu->fixPosition(width, height);
	}
}

void BaseGameState::unload(void)
{
	//unload your objects
}

void BaseGameState::onPaint(SDL_Renderer *renderer)
{

}

void BaseGameState::onQuit(SDL_Event *evt)
{
    running = false;
}

void BaseGameState::tickActions(void)
{
    std::list<SDL_Keycode>::iterator klit(keyDowns.begin()), klend(keyDowns.end());
    for(;klit!=klend;++klit)
    {
        std::list<BaseGameAction*>::iterator glit(actions.begin()), glend(actions.end());
        for(;glit!=glend;++glit)
        {
            (*glit)->testKeycode((*klit));
        }
    }

    std::list<Uint8>::iterator mlit(mouseButtons.begin()), mlend(mouseButtons.end());
    for(;mlit!=mlend;++mlit)
    {
        std::list<BaseGameAction*>::iterator glit(actions.begin()), glend(actions.end());
        for(;glit!=glend;++glit)
        {
            (*glit)->testMouse((*mlit));
        }
    }
}

void BaseGameState::onEvent(SDL_Event *evt)
{
    //keyboard event handling
    if(evt->type == SDL_KEYDOWN)
    {
        KeyEventArgs *args = new KeyEventArgs(evt);
        keyDowns.push_back(evt->key.keysym.sym);
        publish(this, args);
        delete args;
    }
    else if(evt->type == SDL_KEYUP)
    {
        KeyEventArgs *args = new KeyEventArgs(evt);
        keyDowns.remove(evt->key.keysym.sym);
        publish(this, args);
        delete args;
    }
    else if(evt->type == SDL_MOUSEBUTTONDOWN)
    {
        Uint8 mbutton = evt->button.button;
        mouseButtons.push_back(mbutton);
    }
    else if(evt->type == SDL_MOUSEBUTTONUP)
    {
		if(gameMenu != 0)
		{
			if(gameMenu->isVisible() && gameMenu->contains(evt->button.x, evt->button.y))
			{
				Point relpt = Point(evt->button.x - gameMenu->getX(), evt->button.y - gameMenu->getY());
				gameMenu->onClick(&relpt);
			}
		}

        Uint8 mbutton = evt->button.button;
        mouseButtons.remove(mbutton);
    }
	else if(evt->type == SDL_MOUSEMOTION)
	{
		if(gameMenu != 0)
		{
			if(gameMenu->isVisible() && gameMenu->contains(evt->motion.x, evt->motion.y))
			{
				Point relpt = Point(evt->motion.x - gameMenu->getX(), evt->motion.y - gameMenu->getY());
				gameMenu->onMouseMotion(&relpt);
			}
		}
	}

    if(handleQuit && evt->type == SDL_QUIT)
    {
        onQuit(evt);
    }
}

void BaseGameState::openGameMenu(void)
{
	if(gameMenu != 0)
	{
		gameMenu->setVisible(true);
	}
}

void BaseGameState::closeGameMenu(void)
{
	if(gameMenu != 0)
	{
		gameMenu->setVisible(false);
	}
}

void BaseGameState::renderGameMenu(void)
{
	if(gameMenu != 0)
	{
	    if(gameMenu->getX() == 0 && gameMenu->getY() == 0 && gameMenu->getPosition() != Gui::OP_TOP_LEFT_CORNER)
        {
            gameMenu->fixPosition(width, height);
        }

		if(gameMenu->isVisible())
		{
		    std::cout << "VISIBLE" << std::endl;
			Surface *sur = gameMenu->render();

			Texture *tex = new Texture(viewport->getRenderer(), sur->getSDLSurface());

			SDL_Rect *src = sur->getRect();
			SDL_Rect *dst = sur->getRect(gameMenu->getX(), gameMenu->getY());

			tex->renderCopy(src, dst);

			delete sur;
			delete tex;
			delete src;
			delete dst;
		}
	}
}

bool BaseGameState::isHandleQuit(void)
{
    return handleQuit;
}

BaseGameState::~BaseGameState(void)
{
	//todo
}
}
