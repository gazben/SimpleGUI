#ifndef Button_h__
#define Button_h__

#include <string>

#include "GUIelement.h"

class RadioButton :public GUIelement{
public:

	RadioButton(double _x, double _y, double _width, double _height);

	RadioButton(const RadioButton& _inButton);

	virtual void Show();

	bool isClicked();

	virtual GUIelement* clone() const;

	virtual void ProcessUserEvents(GLFWwindow*);

	double getTimeClicked();

	void setClicked(bool _clicked);

private:

	bool clicked;
	double timeClicked;
};

#endif // Button_h__
