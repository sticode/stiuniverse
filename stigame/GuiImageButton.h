#pragma once
#include "GuiItem.h"
#include "EventThrower.h"

namespace StiGame
{
/// \class GuiImageButton
/// \brief A Gui Button that use Image for rendering
class GuiImageButton :
	public GuiItem,
	public EventThrower
{
public:
	/// \brief Default Offset
	static const int DEFAULT_OFFSET = 4;
	/// \brief Create a new Image Button
	GuiImageButton(void);
	/// \brief Destructor
	~GuiImageButton(void);
	/// \brief Autosize the button
	void autosize(void);
	/// \brief Get Button Image
	/// \return Surface
	Surface *getImage(void);
	/// \brief Get Hover Button Image
	/// \return Surface
	Surface *getImageHover(void);
	/// \brief Set the Button Image
	/// \param m_image Image
	void setImage(Surface *m_image);
	/// \brief Set the Hover Button Image
	/// \param m_imageHover Image
	void setImageHover(Surface *m_imageHover);
	/// \brief Render the Image Button
	/// \return Rendered Item
	virtual Surface *render(void);
	/// \brief Clear the item
	void clear(void);
	/// \brief On Click event
	/// \param relp Relative mouse position
	void onClick(Point *relp);

protected:
	/// \brief Highlight Foreground Color
	SColor *highlightForeground;
	/// \brief Highlight Background Color
	SColor *highlightBackground;
	/// \brief Button Image
	Surface *image;
	/// \brief Hover Button Image
	Surface *imageHover;
	/// \brief Offset Width
	int offsetWidth;
	/// \brief Offset Height
	int offsetHeight;
};

}

