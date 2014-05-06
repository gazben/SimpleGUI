#ifndef TextBox_h__
#define TextBox_h__

#include "GUIelement.h"

#include <string>

class TextBox :public GUIelement{

public:
	virtual void Show();

	virtual void ProcessUserEvents(GLFWwindow* window);

	virtual GUIelement* clone() const;

private:

	std::string text;
};
#endif // TextBox_h__