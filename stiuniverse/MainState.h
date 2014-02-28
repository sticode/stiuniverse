#ifndef MAINSTATE_H
#define MAINSTATE_H
#include "BaseGameState.h"
#include "Viewport.h"
#include "ISprite.h"
#include "SpriteLibrary.h"
#include "ClonedSprite.h"
#include "DirectionSprite.h"
#include "MultiRect.h"
#include "BaseMissile.h"
#include "SpaceVessel.h"
#include "BaseGameAction.h"
#include "ActionBinding.h"
#include "MissileFactory.h"
#include "SpaceHud.h"
#include <map>

//need to refactor this to SpaceTravelState or something like this
namespace StiUniverse
{


class MainState : public StiGame::BaseGameState,
    public StiGame::KeyEventListener
{
    public:
        MainState();
        virtual ~MainState();
        void onStart(void);
        void onPaint(SDL_Renderer *renderer);
        void onResize(int m_width,int m_height);
        void onQuit(SDL_Event *evt);
        void onEvent(SDL_Event *evt);
        void unload(void);

        void handleEvent(StiGame::KeyEventThrower *src, StiGame::KeyEventArgs *args);
        void quit(void);
    protected:
        void createViewMovRects(void);
        void updateViewMovRects(void);
        void tickViewMovement(void);
        void moveView(int direction);
        //std::list<SDL_Keycode> keyDowns;
        //ActionBinding *bindings;
        StiGame::SpriteLibrary sprites;
        //DirectionSprite vessel_sprite;
        SpaceVessel *vessel;
        std::list<StiGame::ClonedSprite*> stars_sprites;
        std::list<StiGame::ClonedSprite*> nebula_sprites;
        std::list<StiGame::BaseMissile*> missiles;

        std::map<StiGame::SDirection, StiGame::Rectangle*> viewMovRects;
        //std::list<BaseGameAction*> actions;
        void throwMissile(MissileType mtype);
        void missilesTick(void);
        void generateStars(void);
        void moveStars(int dx, int dy);
        void loadSprites(void);
		StiGame::Rectangle missileLaunchRect;
        StiGame::MultiRect* getViewMultiRect(void);
        SpaceHud hud;

        long tick;
        int area_width;
        int area_height;
        int real_x;
        int real_y;
		int rel_x;
		int rel_y;
        int speed_y;
        int mouse_x;
        int mouse_y;
    private:
};

}

#endif // MAINSTATE_H
