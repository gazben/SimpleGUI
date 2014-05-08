#ifndef Button_h__
#define Button_h__

#include <string>

#include "GUIelement.h"

class RadioButton :public GUIelement{
public:

	RadioButton(double _x, double _y, double _width, double _height);

	RadioButton(const RadioButton& _inButton);

	virtual void Show();		//draws the Button

	bool isClicked();	//returns true if the button is in clicked state

	virtual GUIelement* clone() const;

	virtual void ProcessUserEvents(GLFWwindow*);	

	double getTimeClicked();		//returns the time when the button was clicked in secounds

	void setClicked(bool _clicked);		//manually set the button state

private:

	bool clicked;
	double timeClicked;
};

#endif // Button_h__
