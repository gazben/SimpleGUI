#ifndef Keyboard_h__
#define Keyboard_h__

#define GLFW_DLL
#include <GLFW/glfw3.h>

class Key{
	Key(char _key);

	const char key;

	bool isPressed();

	void setPressed();

	void setReleased();

private:

	bool pressed;

	bool eventFired;
	double timePressed;
};

class Keyboard{
public:

	

	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif // Keyboard_h__
