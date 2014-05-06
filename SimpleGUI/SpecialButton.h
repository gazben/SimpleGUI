#ifndef SpecialButton_h__
#define SpecialButton_h__

#include "GUIelement.h"

struct GLFWwindow;

class SpecialButton : public GUIelement
{
public:

	SpecialButton(double _x, double _y, double _width, double _height);

	virtual void Show();

	virtual void ProcessUserEvents(GLFWwindow* window);

	virtual GUIelement* clone() const;

	//void(*ButtonDoneEvent)(void);

	double getButtonValue();;

private:

	double Button_value;

	bool pressed;
	double clicked_time;
};
#endif // SpecialButton_h__
