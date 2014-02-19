#ifndef GUICHECKBOX_H
#define GUICHECKBOX_H
#include "GuiItem.h"
#include "CheckEventThrower.h"
#include <string>

namespace StiGame
{

/// \class GuiCheckBox
/// \brief Check Box Gui Item
class GuiCheckBox :
    public GuiItem,
    public CheckEventThrower
{
    public:
		/// \brief Create a new Check Box
        GuiCheckBox();
		/// \brief Destructor
        virtual ~GuiCheckBox();
		/// \brief Render Check Box
		/// \return Rendered Check Box
        Surface *render(void);
		/// \brief Get Text Caption
		/// \return Caption Text
        std::string getCaption(void);
		/// \brief Set the caption text
		/// \param m_caption Text
        void setCaption(std::string m_caption);
		/// \brief Is Checked
		/// \return Checked or not
        bool isChecked(void);
		/// \brief Set Checked
		/// \param m_checked Checked Value
        void setChecked(bool m_checked);
        /// \brief On Clieck Event
		/// \param relp Relative Mouse position
		void onClick(Point *relp);
    protected:
		/// \brief Render the Caption Text
        void renderCaption();
		/// \brief Caption Font
        SFont *font;
		/// \brief Caption Text Buffer
        Surface *stringBuffer;
		/// \brief Empty Check Box Image
        Surface *surfaceEmpty;
		/// \brief Checked Check Box Image
        Surface *surfaceChecked;
		/// \brief Caption Text Offset
        int captionOffset;
		/// \brief Default Caption Text Offset
        static const int DefaultCaptionOffset;
		/// \brief Checked value
        bool checked;
		/// \brief Caption Text
        std::string caption;
    private:
};

}

#endif // GUICHECKBOX_H
