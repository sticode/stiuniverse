#ifndef ACTIONMAP_H
#define ACTIONMAP_H

#include "SDL.h"
#include <string>
#include "MouseButtonEvent.h"

namespace StiGame
{
	enum InputType { IT_KEYBOARD, IT_MOUSE, IT_JOYSTICK, IT_DEFAULT };

	class ActionMap
	{
		public:
			ActionMap(void);
			virtual ~ActionMap(void);
			std::string getName(void);
			void setName(std::string m_name);
			virtual void fromString(std::string str);
			virtual std::string toString(void);
			//InputType getInputType(void);
			virtual bool isInput(InputType it);
			static ActionMap* FromString(std::string a_name, std::string action);
			virtual bool inputEquals(InputType it, int input) = 0;
			virtual bool inputMouseEquals(MouseButtonEvent *mbEvt);
			virtual bool isPositionChecked(void);
		protected:
		    InputType inputType;
			std::string name;
	};


}

#endif // ACTIONMAP_H
