#ifndef RADIOGROUP_H
#define RADIOGROUP_H

#include <list>
#include "GuiRadioButton.h"

namespace StiGame {

/// \class RadioGroup
/// \brief Radio Group for Radio button
class RadioGroup
{
    public:
		/// \brief Create a new Radio Group
        RadioGroup();
		/// \brief Destructor
        virtual ~RadioGroup();
		/// \brief Add an item to the group
		/// \param radio Radio Button
        void addItem(GuiRadioButton *radio);
		/// \brief Remove an item from the group
		/// \param radio Radio Button
        void removeItem(GuiRadioButton *radio);
		/// \brief Set the specified Radio Button active
		/// \param radio Radio Button to set active
        void setActive(GuiRadioButton *radio);
		/// \brief Get the active Radio Button
		/// \return Radio button
        GuiRadioButton *getActive(void);
    protected:
		/// \brief Radio Button of this group
        std::list<GuiRadioButton*> radioButtons;
		/// \brief Current active Radio Button
        GuiRadioButton *active;
    private:
};

}

#endif // RADIOGROUP_H
