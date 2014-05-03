#ifndef Button_h__
#define Button_h__

#include <GLFW/glfw3.h>
#include "GUIelement.h"

class Button :public GUIelement{
public:

	virtual void Show();

	bool isClicked();

	virtual void ProcessUserEvents(GLFWwindow*);

	virtual GUIelement* clone() const;

private:

	bool clicked;
};

#endif // Button_h__
