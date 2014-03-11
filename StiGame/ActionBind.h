#ifndef ACTIONBIND_H
#define ACTIONBIND_H

#include "Font.h"
#include "HighlightItem.h"
#include "KeyEventListener.h"
#include "MouseEventListener.h"
#include "CompActionMap.h"
namespace StiGame
{

namespace Gui
{

class ActionBind :
	public HighlightItem,
	public KeyEventListener,
	public MouseEventListener
{
public:
	static const int DefaultWidth;
	static const int DefaultHeight;
	ActionBind();
	virtual ~ActionBind();
	Surface* render(void);
	void handleEvent(KeyEventThrower *src, KeyEventArgs *args);
	void handleEvent(MouseEventThrower *src, MouseButtonEvent *args);
	//void onClick(Point *relpt);
	SDL_Keycode getKey(void);
	void setKey(SDL_Keycode m_keycode);
	MouseButton getMouseButton(void);
	void setMouseButton(MouseButton m_mbutton);
	bool isMouseButton(void);
	bool isHandleMouse(void);
	void setHandleMouse(bool m_handleMouse);
	Font* getFont(void);
	void setFont(Font *m_font);
	void fromActionMap(ActionMap *amap);
	void fromActionMap(CompActionMap *cmap, int index);
	ActionMap* createActionMap(std::string a_name);
	static std::string GetMouseString(MouseButton mbutton);
protected:
	SDL_Keycode keycode;
	MouseButton mbutton;
	bool mouseButton;
	bool handleMouse;
	bool focus;
	Font *font;
	Surface *stringBuffer;
	void renderCaption(void);

};

}

}

#endif
