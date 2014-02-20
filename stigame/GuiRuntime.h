#pragma once
#include "Style.h"
namespace StiGame
{
/// \class GuiRuntime
/// \brief Singleton class that hold Gui Object that are created at RunTime
class GuiRuntime
{
private:
	/// \brief Instance
	static GuiRuntime *_instance;
	/// \brief Gui Style
	Gui::Style *style;

protected:
	/// \brief Create the GuiRuntime
	GuiRuntime(void);
	/// \brief Destructor
	~GuiRuntime(void);
public:
	/// \brief Get GuiRuntime Instance
	/// \return Instance
	static GuiRuntime *getInstance(void)
	{
			if(_instance == NULL)
			{
				_instance = new GuiRuntime();
			}

		return _instance;
	}
	/// \brief Get Gui Style
	/// \return Gui Style
	Gui::Style *getStyle(void);

    void ForceStyle(Gui::Style *m_style)
    {
        Gui::Style *oldstyle = style;
        style = m_style;
        delete oldstyle;
    }

    bool isDebug(void)
    {
        #if DEBUG
        return true;
        #endif // DEBUG

        #if RELEASE
        return false;
        #endif // RELEASE
    }
};

}
