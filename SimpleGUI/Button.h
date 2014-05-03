#ifndef Button_h__
#define Button_h__

#include <string>

#include "GUIelement.h"

class Button :public GUIelement{
public:

	Button(std::string _text, double _x, double _y, double _width, double _height);

	Button(const Button& _inButton);

	virtual void Show();

	bool isClicked();

	virtual GUIelement* clone() const;

	virtual void ProcessUserEvents(GLFWwindow*);

private:

	bool clicked;

	std::string text;
};

#endif // Button_h__
