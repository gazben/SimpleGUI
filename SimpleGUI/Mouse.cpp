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

void Mouse::GetMouseButtonState(GLFWwindow* window){
	LeftButtonPressed = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
	RightButtonPressed = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
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

void Mouse::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
}

void Mouse::MousePosCallback(GLFWwindow * window, double _x, double _y){

	int Screen_height;
	int Screen_width;

	glfwGetWindowSize(window, &Screen_width, &Screen_height);

	x = _x;
	y = Screen_height - _y;
	printf("x: %lf , y: %lf\n", x, y);

}