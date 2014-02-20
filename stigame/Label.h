#pragma once
#include "GuiItem.h"

namespace StiGame
{

namespace Gui
{
/// \class Label
/// \brief Text Label
class Label :
	public GuiItem
{
public:
	/// \brief Create a new Label
	Label(void);
	/// \brief Destructor
	~Label(void);
	/// \brief Render the Label
	/// \return Rendered Label
	Surface* render(void);
	/// \brief Set the caption text
	/// \param m_caption Text
	void setCaption(char* m_caption);
	/// \brief Get the current caption text
	/// \return Caption text
	char* getCaption(void);
	/// \brief Set the Label Font
	/// \param m_font Font
	void setFont(SFont *m_font);
	/// \brief Autosize the label with caption text
	void autosize(void);
	/// \brief Set the label transparent
	/// \param m_transparent Transparency
	void setTransparent(bool m_transparent);
	/// \brief Get the label transparency value
	/// \return Transparency
	bool getTransparent(void);
protected:
	/// \brief Render the caption text
	void renderCaption(void);
	/// \brief Transparency
	bool transparent;
	/// \brief Caption text buffer
	Surface *stringBuffer;
	/// \brief Caption font
	SFont *font;
	/// \brief Caption Text
	char* caption;
};
}
}

