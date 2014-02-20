#pragma once
#include "Surface.h"
#include "SColor.h"
#include <string>
#include "Style.h"
#include "SRect.h"
namespace StiGame
{

namespace Gui
{

/// \class GuiItem
/// \brief Base class for GuiItem
class GuiItem :
	public SRect
{
public:
	/// \brief Create an GuiItem
	GuiItem(void);
	/// \brief Create an GuiItem
	/// \param m_name Name of the item
	GuiItem(std::string m_name);
	/// \brief Destructor
	virtual ~GuiItem(void);
	/// \brief GuiItem Render method
	/// \return Rendered surface of the item
	virtual Surface* render(void);
	/// \brief Clear item members
	virtual void clear(void);
	/// \brief Get the name of the item
	/// \return Name
	std::string getName(void);
	/// \brief Set the background color
	/// \param m_background SColor pointer
	void setBackground(SColor* m_background);
	/// \brief Get the background color pointer
	/// \return SColor pointer
	SColor *getBackground(void);
	/// \brief Set the foreground color
	/// \param m_foreground SColor pointer
	void setForeground(SColor* m_foreground);
	/// \brief Get the foreground color
	/// \return SColor pointer
	SColor *getForeground(void);
	/// \brief Get the style of the item
	/// \return GuiStyle pointer
	Style *getStyle(void);
	/// \brief Get mouse over
	bool getMouseOver(void);
	/// \brief Set mouse over
	void setMouseOver(bool);
	/// \brief Virtual method to override, provide mouse position, only over the GuiItem region
	/// \param relp Relative position over the GuiItem
	virtual void onMouseMotion(Point *relp);
	/// \brief Virtual method to override, called when the item is clicked
	virtual void onClick(Point *relp);
protected:
	/// \brief Name of the item
	std::string name;
	/// \brief Background color
	SColor *background;
	/// \brief Foreground color
	SColor *foreground;
	/// \brief Item GuiStyle
	Style *style;
	/// \brief is mouse over
	bool mouseOver;
private:
	/// \brief initialization
	void init(void);
};

}

}
