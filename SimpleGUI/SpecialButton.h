#ifndef SpecialButton_h__
#define SpecialButton_h__

#include "GUIelement.h"

class SpecialButton : public GUIelement
{
public:

	virtual void Show();

	virtual void ProcessUserEvents(GLFWwindow* window);

	virtual GUIelement* clone() const;


private:

	double Slider_value;


#endif // SpecialButton_h__

