#ifndef SpecialButton_h__
#define SpecialButton_h__

#include "GUIelement.h"

struct GLFWwindow;

//Type definition for the callback function when the button is finished with the circle
typedef void(*ButtonDoneEvent)(void);

/*
Represents a Circle spaped button. A callback will be generated if the mouse is clicked and was on the button for two secounds
*/
class SpecialButton : public GUIelement
{
public:

	SpecialButton(double _x, double _y, double _width, double _height);

	virtual void Show();		//draw the button

	virtual void ProcessUserEvents(GLFWwindow* window);

	virtual GUIelement* clone() const;

	double getButtonValue();		//returns the value of the button: MIN:0 MAX:1

	void SetButtonDoneCallback(ButtonDoneEvent);	//set the callback that will be called when the cirle is finished

	void ButtonCallback();		//the callback function

private:

	double Button_value;

	bool pressed;		//true if the button is pressed and the mouse is on the butotn
	double clicked_time;		//stores when the button was clicked in secounds

	ButtonDoneEvent callback;		//the callback function pointer
};

#endif // SpecialButton_h__
