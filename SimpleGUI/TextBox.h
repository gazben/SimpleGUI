#ifndef TextBox_h__
#define TextBox_h__

#include "GUIelement.h"
#include "Color.h"
#include "Font.h"

#include <string>

class Slider;

class TextBox :public GUIelement{
public:

	TextBox(double _x, double _y, double _width, double _height);

	virtual void Show();

	virtual void ProcessUserEvents(GLFWwindow* window);

	virtual GUIelement* clone() const;

	void clear();

	Color& getBackgroundColor();
	Color& getTextColor();

	void setText(std::string);

private:


	std::string text;

	Color backGround;
	Color textColor;

	Font font;
};
#endif // TextBox_h__