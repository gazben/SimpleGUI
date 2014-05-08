#include "Keyboard.h"

 #define GLFW_DLL
 #include <GLFW/glfw3.h>

void Key::setReleased(){
	pressed = false;
}

void Key::setPressed(){
	pressed = true;
}

/*
Returns true if a button was held more than 0.3 secounds (to not write out a lot of characters)
*/
bool Key::isPressed()
{
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
	return false;
}

Key::Key(char _key) :key(_key){
	timePressed = glfwGetTime();
}

void Keyboard::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
}