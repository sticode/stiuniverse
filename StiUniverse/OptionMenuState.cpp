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
	
	acThrowMissile2 = Gui::ActionBind();
	acThrowMissile2.setX(100);
	acThrowMissile2.setY(350);
	acThrowMissile2.setHandleMouse(true);
	
	lblThrowMissile2 = Gui::Label();
	lblThrowMissile2.setX(20);
	lblThrowMissile2.setY(350);
	lblThrowMissile2.setCaption("Missile 2 : ");
	
	acThrowMissile3 = Gui::ActionBind();
	acThrowMissile3.setX(100);
	acThrowMissile3.setY(400);
	acThrowMissile3.setHandleMouse(true);
	
	lblThrowMissile3 = Gui::Label();
	lblThrowMissile3.setX(20);
	lblThrowMissile3.setY(400);
	lblThrowMissile3.setCaption("Missile 3 : ");
	
    KeyEventThrower::subscribe(&keyUp);
    KeyEventThrower::subscribe(&keyDown);
    KeyEventThrower::subscribe(&keyRight);
    KeyEventThrower::subscribe(&keyLeft);

	KeyEventThrower::subscribe(&acThrowMissile1);
	MouseButtonEventThrower::subscribe(&acThrowMissile1);
	
	KeyEventThrower::subscribe(&acThrowMissile2);
	MouseButtonEventThrower::subscribe(&acThrowMissile2);
	
	KeyEventThrower::subscribe(&acThrowMissile3);
	MouseButtonEventThrower::subscribe(&acThrowMissile3);
	
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
	add(&acThrowMissile2);
	add(&lblThrowMissile2);
	add(&acThrowMissile3);
	add(&lblThrowMissile3);
}

void OptionMenuState::saveBindings(void)
{
    //KeyActionMap *kmap;
    ActionMap *amap;

	std::string a_name = "move_up";
    bindings.overwrite(a_name, keyUp.createKeyActionMap(a_name));

    a_name = "move_down";
    bindings.overwrite(a_name, keyDown.createKeyActionMap(a_name));

    a_name = "move_right";
    bindings.overwrite(a_name, keyRight.createKeyActionMap(a_name));

    a_name = "move_left";
    bindings.overwrite(a_name, keyLeft.createKeyActionMap(a_name));

	a_name = "throw_missile1";
	bindings.overwrite(a_name, acThrowMissile1.createActionMap(a_name));
	
	a_name = "throw_missile2";
	bindings.overwrite(a_name, acThrowMissile2.createActionMap(a_name));
	
	a_name = "throw_missile3";
	bindings.overwrite(a_name, acThrowMissile3.createActionMap(a_name));
	
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
	
    ActionMap *amap;

    amap = bindings.getBinding("move_up");
	keyUp.fromActionMap(amap);

    amap = bindings.getBinding("move_down");
    keyDown.fromActionMap(amap);

    amap = bindings.getBinding("move_right");
    keyRight.fromActionMap(amap);

    amap = bindings.getBinding("move_left");
    keyLeft.fromActionMap(amap);

	amap = bindings.getBinding("throw_missile1");
	acThrowMissile1.fromActionMap(amap);
	
	amap = bindings.getBinding("throw_missile2");
	acThrowMissile2.fromActionMap(amap);
	
	amap = bindings.getBinding("throw_missile3");
	acThrowMissile3.fromActionMap(amap);
	
    running = true;
}

OptionMenuState::~OptionMenuState()
{
    //dtor
}

}
