#ifndef Keyboard_h__
#define Keyboard_h__

#define GLFW_DLL
#include <GLFW/glfw3.h>

class Key{
	Key(char _key) :key(_key){
		timePressed = glfwGetTime();
	}

	const char key;

	bool isPressed(){
		if (pressed){
			if (glfwGetTime() - timePressed > 0.3 && eventFired){
				timePressed = glfwGetTime();
				eventFired = true;
				return true;
			}
			else if (!eventFired){
				eventFired = true;
				return true;
			}
		}
		else
		{
			eventFired = false;

			return false;
		}
	}

private:

	bool pressed;

	bool eventFired;
	double timePressed;
};

class Keyboard{
};

#endif // Keyboard_h__
