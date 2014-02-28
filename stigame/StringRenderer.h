#ifndef STRINGRENDERER_H
#define STRINGRENDERER_H

#include "SFont.h"
#include <string>

namespace StiGame
{

class StringRenderer :
	Dimension
{
public:
	StringRenderer();
	virtual ~StringRenderer();
	
	void setFont(SFont *m_font);
	SFont* getFont(void);
	
	void setColor(Color *m_color);
	Color* getColor(void);
	
	void setText(std::string m_text);
	std::string getText(void);
	
	Surface* getSurface(void);
protected:
	std::string text;
	void renderSurface(void);
	Surface *renderedString;
	SFont *font;
	Color *color;
};


}


#endif