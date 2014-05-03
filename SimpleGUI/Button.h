#ifndef Button_h__
#define Button_h__

#include "GUIelement.h"

#include <GLFW/glfw3.h>

class Button :public GUIelement{
public:

	virtual void Show();

	bool isClicked();

	virtual void ProcessUserEvents(GLFWwindow*);

	virtual GUIelement* clone() const;

private:

	bool clicked;
}

#endif // Button_h__
