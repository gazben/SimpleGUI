#ifndef Slider_h__
#define Slider_h__

#include "GUIelement.h"

class Slider :public GUIelement
{
public:

	Slider(double _x, double _y, double _width, double _height, bool _horizontal = true);

	virtual void Show();

	virtual void ProcessUserEvents(GLFWwindow* window);

	virtual GUIelement* clone() const;

	double getValue();

private:

	double Slider_value;		//MIN: 0 , MAX: 1
	bool horizontal;	//orientation of the slider
};

#endif // Slider_h__
