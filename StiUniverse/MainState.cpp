#include "MainState.h"
#include <iostream>
#include "GamePath.h"
#include <cmath>
#include "DirectionSpriteFile.h"
#include "BatVessel.h"
#include "GameActionFactory.h"
#include "Time.h"
#include "GameOverlay.h"
#include "OverlayGameAction.h"


using namespace StiGame;

namespace StiUniverse {

MainState::MainState() : BaseGameState()
{
    //ctor
    area_width = 3000;
    area_height = 8000;
    mouse_x = 0;
    mouse_y = 0;
	missileLaunchRect = Rectangle();
    tick = 0;
    speed_y = -50;
    KeyEventThrower::subscribe(this);
	rel_x = 0;
	rel_y = 0;
	vessel = new BatVessel();
	hud = SpaceHud();
}

void MainState::quit(void)
{
    running = false;
}

void MainState::handleEvent(KeyEventThrower *src, KeyEventArgs *args)
{
    int multi = 20;

    /*if(args->getState() == KS_DOWN)
    {
        keyDowns.push_back(args->getKeyboardEvent()->keysym.sym);
    }
    else if(args->getState() == KS_UP)
    {
        keyDowns.remove(args->getKeyboardEvent()->keysym.sym);
    }*/
    //keyDowns.unique();
    /*if(args->getKeyboardEvent()->keysym.sym == SDLK_UP)
    {
        moveStars(0,1*multi);
    }
    else if(args->getKeyboardEvent()->keysym.sym == SDLK_DOWN)
    {
        moveStars(0,-1*multi);
    }*/
    /*
    if(args->getKeyboardEvent()->keysym.sym == SDLK_LEFT)
    {
        real_x -= multi*1;
        //vessel_sprite.setDirection(SD_LEFT);
        vessel->move(SD_LEFT);
    }
    else if(args->getKeyboardEvent()->keysym.sym == SDLK_RIGHT)
    {
        real_x += multi*1;
        //vessel_sprite.setDirection(SD_RIGHT);
        vessel->move(SD_RIGHT);
    }
    else if(args->getKeyboardEvent()->keysym.sym == SDLK_SPACE && args->getState() == KeyDown)
    {
        //vessel_sprite.setDirection(SD_UP);
        vessel->move(SD_UP);
    }
    else if(args->getKeyboardEvent()->keysym.sym == SDLK_w && args->getState() == KeyDown)
    {
        throwMissile(MT_BIGORANGE);
    }*/
}

void MainState::throwMissile(MissileType mtype)
{
	if(missileLaunchRect.contains(mouse_x, mouse_y))
	{
        Point *spr_center = vessel->getSprite()->getCenter();

        double d_x = mouse_x - spr_center->getX();
        double d_y = mouse_y - spr_center->getY();

        double angle = atan2(d_y, d_x);

        int mi_x = rel_x + spr_center->getX();
        int mi_y = rel_y + spr_center->getY();

        //BigOrangeMissile *missile = new BigOrangeMissile(viewport->getRenderer(), mi_x, mi_y, angle);
        missiles.push_back(MissileFactory::CreateMissile(mtype, viewport->getRenderer(), mi_x, mi_y, angle));

        delete spr_center;
	}
}

void MainState::missilesTick(void)
{
    std::list<BaseMissile*>::iterator lit(missiles.begin()), lend(missiles.end());
    std::list<BaseMissile*> to_remove;

    SDL_Rect src_rect = SDL_Rect();
    SDL_Rect dst_rect = SDL_Rect();
    SDL_Point center = SDL_Point();

    //damage on his way...
    for(;lit!=lend;++lit)
    {
        if((*lit)->isEnded())
        {
            to_remove.push_back((*lit));
        }
        else
        {
            (*lit)->tick();
            Texture *tex = (*lit)->getTexture();

            src_rect.w = tex->getWidth();
            src_rect.h = tex->getHeight();
            src_rect.x = 0;
            src_rect.y = 0;
            dst_rect.w = tex->getWidth();
            dst_rect.h = tex->getHeight();
            dst_rect.x = (*lit)->getCurrentX() - rel_x;
            dst_rect.y = (*lit)->getCurrentY() - rel_y;

            center.x = src_rect.w / 2;
            center.y = src_rect.h / 2;

            tex->renderCopyEx(&src_rect, &dst_rect, (*lit)->getAngle(Math::AU_DEGREE), &center, SDL_FLIP_NONE);
        }
    }

    std::list<BaseMissile*>::iterator rit(to_remove.begin()), rnd(to_remove.end());

    for(;rit!=rnd;++rit)
    {
        missiles.remove((*rit));
        delete (*rit);
    }
}

void MainState::moveStars(int dx, int dy)
{
    std::list<ClonedSprite*>::iterator lit(stars_sprites.begin()), lend(stars_sprites.end());
    for(;lit!=lend;++lit)
    {
        int x = (*lit)->getX();
        int y = (*lit)->getY();

        x = (x + dx) % area_width;
        y = (y + dy) % area_height;
    }
}

void MainState::onEvent(SDL_Event *evt)
{
    BaseGameState::onEvent(evt);

    if(evt->type == SDL_MOUSEBUTTONDOWN)
    {
		if(gameMenu != 0)
		{
			if(gameMenu->isVisible())
			{
				return;
			}
		}

        mouse_x = evt->button.x;
        mouse_y = evt->button.y;

        Point *spr_center = vessel->getSprite()->getCenter();

        double d_x = mouse_x - spr_center->getX();
        double d_y = mouse_y - spr_center->getY();
        delete spr_center;

        if(evt->button.button == SDL_BUTTON_LEFT)
        {
            //RedMissile *missile = new RedMissile(viewport->getRenderer(), mi_x, mi_y, angle);
            //BaseMissile *missile = BaseMissile::CreateMissile(MT_RED, viewport->getRenderer(), mi_x, mi_y, angle);
            //missiles.push_back(missile);
            //throwMissile(MT_RED);

            double angle = atan2(d_y, d_x);

            missiles.push_back(vessel->throwMissile(0, viewport->getRenderer(), angle));
        }
        else if(evt->button.button == SDL_BUTTON_RIGHT)
        {
            //GreenMissile *missile = new GreenMissile(viewport->getRenderer(), mi_x, mi_y, angle);

            //missiles.push_back(BaseMissile::CreateMissile(MT_GREEN, viewport->getRenderer(), mi_x, mi_y, angle));
            double angle = atan2(d_y, d_x);

            missiles.push_back(vessel->throwMissile(1, viewport->getRenderer(), angle));
        }

    }
    else if(evt->type == SDL_MOUSEMOTION)
    {
        mouse_x = evt->motion.x;
        mouse_y = evt->motion.y;
    }
}

void MainState::createViewMovRects(void)
{
    Rectangle *rect = new Rectangle();

    rect->setX(0);
    rect->setY(0);
    rect->setWidth(width);
    rect->setHeight(100);

    viewMovRects.insert(std::make_pair(SD_UP, rect));

    rect = new Rectangle();

    rect->setX(0);
    rect->setY(height - 100);
    rect->setWidth(width);
    rect->setHeight(100);

    viewMovRects.insert(std::make_pair(SD_DOWN, rect));

    rect = new Rectangle();
    rect->setX(0);
    rect->setY(0);
    rect->setWidth(100);
    rect->setHeight(height);

    viewMovRects.insert(std::make_pair(SD_LEFT, rect));

    rect = new Rectangle();
    rect->setX(width - 100);
    rect->setY(0);
    rect->setWidth(100);
    rect->setHeight(height);

    viewMovRects.insert(std::make_pair(SD_RIGHT, rect));
}

MultiRect* MainState::getViewMultiRect()
{
    MultiRect *rects = new MultiRect();

    int max_x = (rel_x + width) % area_width;
    int max_y = (rel_y + height) % area_height;

    if(rel_x > max_x && rel_y > max_y)
    {
        //four square method
        rects->addRect(rel_x, rel_y, area_width - rel_x, area_height - rel_y);
        rects->addRect(rel_x, 0, area_width - rel_x, max_y);
        rects->addRect(0, rel_y, max_x, area_height - rel_y);
        rects->addRect(0, 0, max_x, max_y);
    }
    else if(rel_y > max_y && rel_x < max_x)
    {
        //two square
        rects->addRect(rel_x, rel_y, max_x - rel_x, area_height - rel_y);
        rects->addRect(rel_x, 0, max_x - rel_x, max_y);
    }
    else if(rel_x > max_x && rel_y < max_y)
    {
        //two quare
        rects->addRect(rel_x, rel_y, area_width - rel_x, max_y - rel_y);
        rects->addRect(0, rel_y, max_x, max_y - rel_y);
    }
    else
    {
        //normal one
        rects->addRect(rel_x, rel_y, max_x - rel_x, max_y - rel_y);
    }

    return rects;
}

void MainState::onPaint(SDL_Renderer *renderer)
{
    if(!gameMenu->isVisible())
    {

    tick++;
    tickViewMovement();
    tickActions();

    vessel->tick();

    }

    //vessel_sprite.setX((width - vessel_sprite.getWidth()) / 2);
    //vessel_sprite.setY(height - vessel_sprite.getHeight() - 50);
    //sprite testing

    //missileLaunchRect.setHeight(vessel_sprite.getY());
    /*if(tick % 2 == 0)
    {
        if(tick < 255)
        {
            glogo.setAlpha( 255 - tick );
        }
    }*/

    //GuiState::onPaint(renderer);
    //some custom code here
    //moveStars(0, speed_y);
    //real_y = real_y + speed_y;

    rel_x = real_x % area_width;
    rel_y = real_y % area_height;

    if(rel_x < 0)
    {
        rel_x = area_width + rel_x;
    }

    if(rel_y < 0)
    {
        rel_y = area_height + rel_y;
    }

    MultiRect *rects = getViewMultiRect();

    //drawing nebula
    std::list<ClonedSprite*>::iterator nlit(nebula_sprites.begin()), nlend(nebula_sprites.end());
    for(;nlit!=nlend;++nlit)
    {
        if(rects->contains((*nlit)))
        {
            int tmp_x = (*nlit)->getX();
            int tmp_y = (*nlit)->getY();
            int s_x = tmp_x;
            int s_y = tmp_y;

            if(tmp_x < rel_x)
            {
                s_x = area_width - rel_x + tmp_x;
            }
            else
            {
                s_x = tmp_x - rel_x;
            }

            if(tmp_y < rel_y)
            {
                s_y = area_height - rel_y + tmp_y;
            }
            else
            {
                s_y = tmp_y - rel_y;
            }

            //swaping coord
            (*nlit)->set(s_x, s_y);
            (*nlit)->render();
            (*nlit)->set(tmp_x, tmp_y);
        }
    }

    //drawing stats
    std::list<ClonedSprite*>::iterator lit(stars_sprites.begin()), lend(stars_sprites.end());

    for(;lit!=lend;++lit)
    {
        if(rects->contains((*lit)->getX(), (*lit)->getY()))
        {
            int tmp_x = (*lit)->getX();
            int tmp_y = (*lit)->getY();
            int s_x = tmp_x;
            int s_y = tmp_y;

            if(tmp_x < rel_x)
            {
                s_x = area_width - rel_x + tmp_x;
            }
            else
            {
                s_x = tmp_x - rel_x;
            }

            if(tmp_y < rel_y)
            {
                s_y = area_height - rel_y + tmp_y;
            }
            else
            {
                s_y = tmp_y - rel_y;
            }

            //swaping coord
            (*lit)->set(s_x, s_y);
            (*lit)->render();
            (*lit)->set(tmp_x, tmp_y);

        }
    }

    rects->clear();
    delete rects;

    missilesTick();

    //vessel_sprite.render();
    DirectionSprite *vessel_spr = vessel->getSprite();
    vessel_spr->set(vessel->getX() - real_x, vessel->getY() - real_y);
    vessel_spr->render();


    BaseGameState::onPaint(renderer);
}

void MainState::generateStars(void)
{
    int nb_stars = 8000;
    int nb_nebula = 50;

    //generate some nebula
    for(int i=0; i<nb_nebula; i++)
    {
        int x = rand() % (area_width + width);
        int y = rand() % (area_height + height);

        int ntype = rand() % 2;

        ClonedSprite *spr;

        switch(ntype)
        {
        case 0:
            spr = sprites.clone("nebula0");
            break;
        case 1:
            spr = sprites.clone("nebula1");
            break;
        default:
            spr = sprites.clone("nebula0");
        }

        spr->set(x, y);
        nebula_sprites.push_back(spr);
    }

    for(int i=0; i<nb_stars; i++)
    {
        int x = rand() % (area_width + width);
        int y = rand() % (area_height + height);

        int stype = rand() % 10;
        ClonedSprite *spr;
        switch(stype)
        {
            case 0:
                spr = sprites.clone("a0");
                break;
            case 1:
                spr = sprites.clone("a1");
                break;
            case 2:
                spr = sprites.clone("a2");
                break;
            case 3:
                spr = sprites.clone("a3");
                break;
            case 4:
                spr = sprites.clone("a4");
                break;
            case 5:
                spr = sprites.clone("a5");
                break;
            case 6:
                spr = sprites.clone("a6");
                break;
            case 7:
                spr = sprites.clone("a7");
                break;
            case 8:
                spr = sprites.clone("d0");
                break;
            case 9:
                spr = sprites.clone("d1");
                break;
            default:
                spr = sprites.clone("a8");
        }

        spr->setX(x);
        spr->setY(y);
        stars_sprites.push_back(spr);
    }
}

void MainState::unload(void)
{

}


void MainState::onResize(int m_width, int m_height)
{
    BaseGameState::onResize(m_width, m_height);
	missileLaunchRect.setWidth(m_width);
	missileLaunchRect.setHeight(m_height);

    hud.setWidth(m_width);
    hud.setHeight(50);

    hud.setX(0);
    hud.setY(m_height - hud.getHeight());

    updateViewMovRects();

    if(viewMovRects.size() != 0)
    {
        viewMovRects[SD_UP]->setWidth(m_width);
        viewMovRects[SD_DOWN]->setWidth(m_width);
        viewMovRects[SD_LEFT]->setHeight(m_height);
        viewMovRects[SD_RIGHT]->setHeight(m_height);
    }
}

void MainState::onQuit(SDL_Event *evt)
{
    running = false;
}

void MainState::loadSprites(void)
{
    //DirectionSpriteFile *vesselFile = new DirectionSpriteFile(GamePath::getFilepath(AssetSprite, "vessel0" + DirectionSpriteFile::FILE_EXTENSION));
    //vessel_sprite = DirectionSprite(vesselFile, viewport->getRenderer());

    //vessel_sprite = (*vesselFile->getDirectionSprite(viewport->getRenderer()));

    //delete vesselFile;
    vessel->loadSprite(viewport->getRenderer());
    sprites = SpriteLibrary(viewport->getRenderer());
    sprites.load("nebula0");
    sprites.load("nebula1");

    sprites.load("a0", ST_SPRITEFILE);
    sprites.load("a1", ST_SPRITEFILE);
    sprites.load("a2", ST_SPRITEFILE);
    sprites.load("a3", ST_SPRITEFILE);
    sprites.load("a4", ST_SPRITEFILE);
    sprites.load("a5", ST_SPRITEFILE);
    sprites.load("a6", ST_SPRITEFILE);
    sprites.load("a7", ST_SPRITEFILE);
    sprites.load("d0", ST_SPRITEFILE);
    sprites.load("d1", ST_SPRITEFILE);
}

void MainState::onStart(void)
{
    unsigned long long load_time = Time::GetMsTimestamp();
    bindings = ActionBinding(ActionBinding::FILENAME.c_str());
    bindings.read();

    GameOverlay *overlay = new GameOverlay();
    overlay->setState(this);
    KeyEventThrower::subscribe(overlay);

    gameMenu = overlay;


	GameActionFactory::PopulateMovement(actions, vessel);
    GameActionFactory::MapAction(actions, &bindings);
	//Default OverlayAction triggered by Escape key, this action will not ne mappable !
    BaseGameAction *o_action = OverlayGameAction::GetDefaultOverlayGameAction(this);

    actions.push_back(o_action);

    std::cout << actions.size() << std::endl;
    //loading sprite here!!
    std::cout << "loading sprites" << std::endl;
    loadSprites();

    std::cout << "generating stars" << std::endl;
    generateStars();

    load_time = Time::GetMsTimestamp() - load_time;
    std::cout << "loading just took " << load_time << "ms !" << std::endl;

    real_y = area_height - height;
    real_x = (area_width - viewport->getWidth())/2;

	missileLaunchRect.setWidth(width);
	missileLaunchRect.setHeight(height);

	vessel->spawnVessel(real_x + (width / 2) , area_height - 100);

    running = true;

    createViewMovRects();
    updateViewMovRects();

    hud.setVessel(vessel);

    hud.setVisible(true);

    frames.push_back(&hud);
}

void MainState::tickViewMovement(void)
{
    std::map<SDirection, Rectangle*>::iterator lit(viewMovRects.begin()), lend(viewMovRects.end());
    int direction = 0;

    for(;lit!=lend;++lit)
    {
        if(lit->second->contains(vessel->getX(), vessel->getY()))
        {
            direction += lit->first;
        }
    }

    if(direction != 0)
    {
        moveView(direction);
    }
}

void MainState::moveView(int direction)
{
    if( (direction & SD_UP) == SD_UP)
    {
        real_y -= vessel->getSpeed();
        updateViewMovRects();
    }

    if( (direction & SD_DOWN) == SD_DOWN)
    {
        real_y += vessel->getSpeed();
        updateViewMovRects();
    }

    if( (direction & SD_LEFT) == SD_LEFT)
    {
        real_x -= vessel->getSpeed();
        updateViewMovRects();
    }

    if( (direction & SD_RIGHT) == SD_RIGHT)
    {
        real_x += vessel->getSpeed();
        updateViewMovRects();
    }
}

void MainState::updateViewMovRects(void)
{
    if(viewMovRects.size() != 0)
    {
        viewMovRects[SD_UP]->setX(real_x);
        viewMovRects[SD_UP]->setY(real_y);

        viewMovRects[SD_DOWN]->setX(real_x);
        viewMovRects[SD_DOWN]->setY(real_y + height - 100);

        viewMovRects[SD_LEFT]->setX(real_x);
        viewMovRects[SD_LEFT]->setY(real_y);

        viewMovRects[SD_RIGHT]->setX(real_x + width - 100);
        viewMovRects[SD_RIGHT]->setY(real_y);
    }
}


MainState::~MainState()
{
    //dtor
}

}
