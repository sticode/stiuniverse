#ifndef GUIKEYBIND_H
#define GUIKEYBIND_H

#include "GuiHighlightItem.h"
#include "KeyEventListener.h"
#include <string>

namespace StiGame {
/* Note(s)
* Add the support for a mouse capture !
*
*/


/// \class GuiKeyBind
/// \brief GuiItem to capture Key Pressed for a Key Bind
class GuiKeyBind :
    public GuiHighlightItem,
    public KeyEventListener
{
    public:
		/// \brief Create a new Gui Key Bind
        GuiKeyBind();
		/// \brief Destructor
        virtual ~GuiKeyBind();
		/// \brief Render the Gui Key Bind
		/// \return Rendered Gui Key Bind
        Surface *render(void);
		/// \brief On Click event
		/// \param relp Relative Mouse position on the Gui Item
        void onClick(Point *relp);
		/// \brief Event Handling
		/// \param src Key Event Thrower
		/// \param args Key Event Arguments
        void handleEvent(KeyEventThrower *src, KeyEventArgs *args);
		/// \brief Default Width
        static const int DefaultWidth;
		/// \brief Default Height
		static const int DefaultHeight;
		/// \brief Get SDL Keycode
		/// \return Key Code
        SDL_Keycode getKey(void);
		/// \brief Set SDL Keycode
		/// \param m_key Key Code
        void setKey(SDL_Keycode m_key);
    protected:
		/// \brief Keycode String Buffer
        Surface *stringBuffer;
		/// \brief Font
        SFont *font;
		/// \brief Key Code
        SDL_Keycode key;
		/// \brief Key String Value
        std::string keyCaption;
		/// \brief Render Caption
        void renderCaption(void);
		/// \brief Is Focused
        bool focus;
    private:
};

}
#endif // GUIKEYBIND_H
