#include "OptionMenuState.h"
#include "MainMenuState.h"
#include "KeyActionMap.h"

using namespace StiGame;

namespace StiUniverse
{

OptionMenuState::OptionMenuState() : GuiState()
{
    //ctor
    btnBack = Gui::Button();
    btnBack.setCaption("Back");
    btnBack.setX(400);
    btnBack.setY(600);

    btnBack.subscribe(this);


    keyUp = Gui::KeyBind();
    keyUp.setX(100);
    keyUp.setY(100);
    keyUp.setKey(SDLK_w);

    lblUp = Gui::Label();
    lblUp.setCaption("Up : ");
    lblUp.setX(20);
    lblUp.setY(100);


    keyDown = Gui::KeyBind();
    keyDown.setX(100);
    keyDown.setY(150);
    keyDown.setKey(SDLK_s);

    lblDown = Gui::Label();
    lblDown.setX(20);
    lblDown.setY(150);
    lblDown.setCaption("Down : ");

    keyRight = Gui::KeyBind();
    keyRight.setX(100);
    keyRight.setY(200);
    keyRight.setKey(SDLK_s);

    lblRight = Gui::Label();
    lblRight.setX(20);
    lblRight.setY(200);
    lblRight.setCaption("Right : ");

    keyLeft = Gui::KeyBind();
    keyLeft.setX(100);
    keyLeft.setY(250);
    keyLeft.setKey(SDLK_s);

    lblLeft = Gui::Label();
    lblLeft.setX(20);
    lblLeft.setY(250);
    lblLeft.setCaption("Left : ");
	
	acThrowMissile1 = Gui::ActionBind();
	acThrowMissile1.setX(100);
	acThrowMissile1.setY(300);
	acThrowMissile1.setHandleMouse(true);
	
	lblThrowMissile1 = Gui::Label();
	lblThrowMissile1.setX(20);
	lblThrowMissile1.setY(300);
	lblThrowMissile1.setCaption("Missile 1 : ");

    KeyEventThrower::subscribe(&keyUp);
    KeyEventThrower::subscribe(&keyDown);
    KeyEventThrower::subscribe(&keyRight);
    KeyEventThrower::subscribe(&keyLeft);

	KeyEventThrower::subscribe(&acThrowMissile1);
	MouseEventThrower::subscribe(&acThrowMissile1);
	
    add(&btnBack);
    add(&keyUp);
    add(&lblUp);
    add(&keyDown);
    add(&lblDown);
    add(&keyRight);
    add(&lblRight);
    add(&keyLeft);
    add(&lblLeft);
	add(&acThrowMissile1);
	add(&lblThrowMissile1);
}

void OptionMenuState::saveBindings(void)
{
    KeyActionMap *kmap;
    ActionMap *amap;
    SDL_Keycode kc;

    kc = keyUp.getKey();
    amap = bindings.getBinding("move_up");
    kmap = dynamic_cast<KeyActionMap*>(amap);
    kmap->setKeycode(kc);

    kc = keyDown.getKey();
    amap = bindings.getBinding("move_down");
    kmap = dynamic_cast<KeyActionMap*>(amap);
    kmap->setKeycode(kc);

    kc = keyRight.getKey();
    amap = bindings.getBinding("move_right");
    kmap = dynamic_cast<KeyActionMap*>(amap);
    kmap->setKeycode(kc);

    kc = keyLeft.getKey();
    amap = bindings.getBinding("move_left");
    kmap = dynamic_cast<KeyActionMap*>(amap);
    kmap->setKeycode(kc);

    bindings.write();
}

void OptionMenuState::handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *args)
{
    if(src == &btnBack)
    {
        saveBindings();
        viewport->push(new MainMenuState());
    }
}

void OptionMenuState::onStart(void)
{
    bindings = ActionBinding(ActionBinding::FILENAME.c_str());

    bindings.read();

    SDL_Keycode kc = SDLK_0;
    int kc_int = 0;
    ActionMap *amap;

    amap = bindings.getBinding("move_up");
    kc_int = amap->getIntValue();
    kc = static_cast<SDL_Keycode>(kc_int);
    keyUp.setKey(kc);

    amap = bindings.getBinding("move_down");
    kc_int = amap->getIntValue();
    kc = static_cast<SDL_Keycode>(kc_int);
    keyDown.setKey(kc);

    amap = bindings.getBinding("move_right");
    kc_int = amap->getIntValue();
    kc = static_cast<SDL_Keycode>(kc_int);
    keyRight.setKey(kc);

    amap = bindings.getBinding("move_left");
    kc_int = amap->getIntValue();
    kc = static_cast<SDL_Keycode>(kc_int);
    keyLeft.setKey(kc);

    running = true;
}

OptionMenuState::~OptionMenuState()
{
    //dtor
}

}
