#ifndef GUIelement_h__
#define GUIelement_h__

#include <GLFW/glfw3.h>

class GUIelement
{
private:

	bool visible;

	float x;
	float y;
	float width;
	float height;

public:

	GUIelement();

	bool isVisible();
	virtual void Show() = 0;
	virtual void ProcessUserEvents(GLFWwindow*) = 0;

	virtual GUIelement* clone() const = 0;  // Virtual constructor for copying 
};

#endif // GUIelement_h__
