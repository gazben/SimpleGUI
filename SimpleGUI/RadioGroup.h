#ifndef RadioGroup_h__
#define RadioGroup_h__

#include <vector>

#include "GUIelement.h"

class RadioButton;

class RadioGroup :public GUIelement{
public:

	RadioGroup();

	virtual void Show();

	virtual void ProcessUserEvents(GLFWwindow* window);

	virtual GUIelement* clone() const;

	void AddElement(RadioButton& _inElement);

private:

	std::vector<RadioButton> RadioButtons;
};

#endif // RadioGroup_h__
