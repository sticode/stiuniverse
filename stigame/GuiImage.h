#pragma once
#include "GuiItem.h"
namespace StiGame
{
/// \class GuiImage
/// \brief Class that permit user to draw an image on a GuiState
class GuiImage :
	public GuiItem
{
public:
    /// \brief Constructor
	GuiImage(void);
	/// \brief Destructor
	~GuiImage(void);
	Surface *render(void);
	/// \brief Set the image with the file path
	/// \param m_imagePath Image path
	void setImage(char* m_imagePath);
	/// \brief Draw border
	/// \param m_drawBorder draw it or not
	void setDrawBorder(bool m_drawBorder);
	/// \brief Set the alpha blending
	/// \param n_alpha Alpha value (0-255)
	void setAlpha(int n_alpha);
protected:
	/// \brief Load the image
    void loadImage(void);
	/// \brief Image Buffer
    Surface *imageBuffer;
	/// \brief Image Path
    char* imagePath;
	/// \brief Draw the border
	bool drawBorder;
};
}
