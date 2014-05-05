#include "Mouse.h"

#define  GLFW_DLL
#include <GLFW/glfw3.h>

#include <stdio.h>

int Mouse::LeftButtonPressed = false;
int Mouse::RightButtonPressed = false;

double Mouse::x = 0;
double Mouse::y = 0;

bool Mouse::isRightButtonPressed(){
	return RightButtonPressed;
}

bool Mouse::isLeftButtonPressed(){
	return LeftButtonPressed;
}

void Mouse::SetMousePosition(GLFWwindow* window, double _x, double _y){
	int Screen_height;
	int Screen_width;

	glfwGetWindowSize(window, &Screen_width, &Screen_height);

	glfwSetCursorPos(window, _x, _y);
	x = _x;
	y = Screen_height - _y;
}

Mouse::Mouse(){
	x = 0;
	y = 0;
}

void Mouse::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods){
	if (button == GLFW_MOUSE_BUTTON_LEFT &&  action == GLFW_PRESS)
		LeftButtonPressed = true;

	if (button == GLFW_MOUSE_BUTTON_LEFT &&  action == GLFW_RELEASE)
		LeftButtonPressed = false;

	if (button == GLFW_MOUSE_BUTTON_RIGHT &&  action == GLFW_PRESS)
		RightButtonPressed = true;

	if (button == GLFW_MOUSE_BUTTON_RIGHT &&  action == GLFW_RELEASE)
		RightButtonPressed = false;

#ifdef _DEBUG
	printf("Current state of mouse buttons: Left: %d  Right: %d\n", LeftButtonPressed , RightButtonPressed );
#endif // _DEBUG

}

void Mouse::MousePosCallback(GLFWwindow * window, double _x, double _y){
	int Screen_height;
	int Screen_width;

	glfwGetWindowSize(window, &Screen_width, &Screen_height);

	x = _x;
	y = Screen_height - _y;

#ifdef _DEBUG
	printf("x: %lf , y: %lf\n", x, y);
#endif
}

double Mouse::GetPosition_x(){
	return x;
}

double Mouse::GetPosition_y(){
	return y;
}