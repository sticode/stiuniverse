#pragma once
#include "SColor.h"
#include "SFont.h"

namespace StiGame
{

namespace Gui
{
/// \class Style
/// \brief Default Color for Gui Element
class Style
{
private:
	/// \brief Foreground Color
	SColor foreground;
	/// \brief Background Color
	SColor background;
	/// \brief Highlight Foreground Color
	SColor highlightForeground;
	/// \brief Highlight Background Color
	SColor highlightBackground;
	/// \brief Drop List Arrow Image
	Surface *dropListArrow;
	/// \brief Up Arrow Image
	Surface *upArrow;
	/// \brief Down Arrow Image
	Surface *downArrow;
	/// \brief Check Box Image
	Surface *checkbox;
	/// \brief Checked Check Box Image
	Surface *checkboxChecked;
	/// \brief Radio Button Image
	Surface *radio;
	/// \brief Checked Radio Button Image
	Surface *radioChecked;
	/// \brief Normal Font
	SFont *normalFont;
public:
	/// \brief Create a new GuiStyle
	GuiStyle(void);
	/// \brief Destructor
	~GuiStyle(void);
	/// \brief Get Foreground Pointer
	SColor *getForeground(void);
	/// \brief Get Background Pointer
	SColor *getBackground(void);
	/// \brief Get Highlight Background Pointer
	SColor *getHighlightBackground(void);
	/// \brief Get Highlight Foreground Pointer
	SColor *getHighlightForeground(void);
	/// \brief Get Up Arrow Image Pointer
	Surface *getUpArrow(void);
	/// \brief Get Down Arrow Image Pointer
	Surface *getDownArrow(void);
	/// \brief Get Drop List Arrow Image Pointer
	Surface *getDropListArrow(void);
	/// \brief Get Checkbox Image Pointer
	Surface *getCheckbox(void);
	/// \brief Get Checked Checkbox Image Pointer
	Surface *getCheckboxChecked(void);
	/// \brief Get Radio Button Image Pointer
	Surface *getRadio(void);
	/// \brief Get Check Radio Button Pointer
	Surface *getRadioChecked(void);
	/// \brief Get Normal Font Pointer
	SFont *getNormalFont(void);
	/// \brief Unload Ressources
	void unload(void);
};

}

}

