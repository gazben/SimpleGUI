#include "Mouse.h"

#define  GLFW_DLL
#include <GLFW/glfw3.h>

#include <stdio.h>

MouseState Mouse::LeftButtonState = MouseState::UP;
MouseState Mouse::RightButtonState = MouseState::UP;
MouseState Mouse::LeftButtonState_last = MouseState::UP;
MouseState Mouse::RightButtonState_last = MouseState::UP;

double Mouse::x = 0;
double Mouse::y = 0;

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

//Handles the current mouse button states
void Mouse::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods){
	LeftButtonState_last = LeftButtonState;
	RightButtonState_last = RightButtonState;

	if (button == GLFW_MOUSE_BUTTON_LEFT &&  action == GLFW_PRESS)
		LeftButtonState = MouseState::DOWN;

	if (button == GLFW_MOUSE_BUTTON_LEFT &&  action == GLFW_RELEASE)
		LeftButtonState = MouseState::UP;

	if (button == GLFW_MOUSE_BUTTON_LEFT &&  action == GLFW_REPEAT)
		LeftButtonState = MouseState::HELD;

	if (button == GLFW_MOUSE_BUTTON_RIGHT &&  action == GLFW_PRESS)
		RightButtonState = MouseState::DOWN;

	if (button == GLFW_MOUSE_BUTTON_RIGHT &&  action == GLFW_RELEASE)
		RightButtonState = MouseState::UP;

	if (button == GLFW_MOUSE_BUTTON_RIGHT &&  action == GLFW_REPEAT)
		RightButtonState = MouseState::HELD;

#ifdef _DEBUG
	printf("Current state of mouse buttons: Left: %d  Right: %d\n", LeftButtonState, RightButtonState);
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

//Returns the X coordinate of the mouse position
double Mouse::GetPosition_x(){
	return x;
}

//Returns the Y coordinate of the mouse position
double Mouse::GetPosition_y(){
	return y;
}

//Returns the Left mouse button's current state
MouseState Mouse::getLeftButtonState(){
	return LeftButtonState;
}

//Returns the Right mouse button's current state
MouseState Mouse::getRightButtonState(){
	return RightButtonState;
}

bool Mouse::isClickLeft(GLFWwindow* window)
{
	bool tempClick = false;

	if (LeftButtonState_last == MouseState::UP &&  glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		tempClick = true;

	if (LeftButtonState_last == MouseState::DOWN &&  glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
		tempClick = false;

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		LeftButtonState = MouseState::DOWN;

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
		LeftButtonState = MouseState::UP;

	LeftButtonState_last = LeftButtonState;

	return tempClick;
}