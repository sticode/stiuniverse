#ifndef HIGHLIGHTITEM_H
#define HIGHLIGHTITEM_H

#include "Item.h"

namespace StiGame
{

namespace Gui
{


/// \class HighlightItem
/// \brief Interface for highlight-able Item
class HighlightItem :
    public Item
{
    public:
		/// \brief Create a new Highlight Item
        HighlightItem();
		/// \brief Destructor
        virtual ~HighlightItem();
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
#endif // HIGHLIGHTITEM_H
