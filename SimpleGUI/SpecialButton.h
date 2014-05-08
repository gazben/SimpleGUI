#ifndef SpecialButton_h__
#define SpecialButton_h__

#include "GUIelement.h"

struct GLFWwindow;

typedef void(*ButtonDoneEvent)(void);

class SpecialButton : public GUIelement
{
public:

	SpecialButton(double _x, double _y, double _width, double _height);

	virtual void Show();

	virtual void ProcessUserEvents(GLFWwindow* window);

	virtual GUIelement* clone() const;

	double getButtonValue();

	void SetButtonDoneCallback(ButtonDoneEvent);

	void ButtonCallback();
private:

	double Button_value;

	bool pressed;
	double clicked_time;

	ButtonDoneEvent callback;
};
#endif // SpecialButton_h__
