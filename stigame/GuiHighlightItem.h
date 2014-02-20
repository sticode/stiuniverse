#ifndef GUIHIGHLIGHTITEM_H
#define GUIHIGHLIGHTITEM_H

#include "GuiItem.h"

namespace StiGame
{

namespace Gui
{


/// \class GuiHighlightItem
/// \brief Interface for highlight-able Item
class GuiHighlightItem :
    public GuiItem
{
    public:
		/// \brief Create a new Highlight Item
        GuiHighlightItem();
		/// \brief Destructor
        virtual ~GuiHighlightItem();
		/// \brief Set highlight Foreground Color
		/// \param color Color
        void setHighlightForeground(SColor *color);
		/// \brief Set highlight Background Color
		/// \param color Color
        void setHighlightBackground(SColor *color);
		/// \brief Get highlight Foreground Color
		/// \return Foreground Color
        SColor *getHighlightForeground(void);
		/// \brief Get highlight Background Color
		/// \return Background Color
        SColor *getHighlightBackground(void);

    protected:
		/// \brief Highlight Foreground Color
        SColor *highlightForeground;
		/// \brief Highlight Background Color
        SColor *highlightBackground;
    private:
};

}

}
#endif // GUIHIGHLIGHTITEM_H
