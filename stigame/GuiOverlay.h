#ifndef GUIOVERLAY_H
#define GUIOVERLAY_H

#include "GuiItem.h"
#include <list>

namespace StiGame
{

enum OverlayPosition { OP_MIDDLE,
					OP_TOP_LEFT_CORNER,
					OP_TOP_RIGHT_CORNER,
					OP_BOTTOM_LEFT_CORNER,
					OP_BOTTOM_RIGHT_CORNER,
					OP_CUSTOM };

class GuiOverlay :
    public Gui::GuiItem
{
    public:
		static const int DEFAULT_OFFSET;
        GuiOverlay();
        virtual ~GuiOverlay();
        virtual void onMouseMotion(Point *relp);
        virtual void onClick(Point *relp);
        virtual Surface* render(void);
        bool isVisible(void);
        void setVisible(bool m_visible);
		OverlayPosition getPosition(void);
		void setPosition(OverlayPosition m_position);
		void fixPosition(int m_width, int m_height);
		void add(GuiItem *item);
    protected:
		GuiItem* getLastItem(void);
		OverlayPosition position;
        std::list<GuiItem*> items;
        bool visible;
		bool autosize;
    private:
};

}

#endif // GUIOVERLAY_H
