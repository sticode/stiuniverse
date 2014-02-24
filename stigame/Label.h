#pragma once
#include "Item.h"
#include <string>
namespace StiGame
{

namespace Gui
{

enum TextAnchor {
    TA_TOP = 1,
    TA_BOTTOM = 2,
    TA_LEFT = 4,
    TA_RIGHT = 8,
    TA_TOP_LEFT =  5,
    TA_TOP_RIGHT = 9,
    TA_BOT_LEFT = 6,
    TA_BOT_RIGHT = 10,
    TA_MIDDLE = 15
};

/// \class Label
/// \brief Text Label
class Label :
	public Item
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
	void setCaption(std::string m_caption);
	/// \brief Get the current caption text
	/// \return Caption text
	std::string getCaption(void);
	/// \brief Set the Label Font
	/// \param m_font Font
	void setFont(SFont *m_font);
	/// \brief Autosize the label with caption text
	void doAutosize(void);
	/// \brief Set the label transparent
	/// \param m_transparent Transparency
	void setTransparent(bool m_transparent);
	/// \brief Get the label transparency value
	/// \return Transparency
	bool getTransparent(void);

	int getAnchors(void);
	void setAnchors(int m_anchors);

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
	std::string caption;
	int anchors;
};
}
}

