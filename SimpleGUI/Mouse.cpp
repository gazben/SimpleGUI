#include "Mouse.h"

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

void Mouse::GetMousePosition(GLFWwindow* window){
	glfwGetCursorPos(window, &x, &y);
}

void Mouse::SetMousePosition(GLFWwindow* window, double _x, double _y){
	glfwSetCursorPos(window, _x, _y);
	x = _x;
	y = _y;
}

void Mouse::ProcessMouseEvents(GLFWwindow* window){
	GetMousePosition(window);
	GetMouseButtonState(window);
}

Mouse::Mouse(){
	x = 0;
	y = 0;
}