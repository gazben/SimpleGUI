#ifndef Mouse_h__
#define Mouse_h__

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Mouse{
public:

	Mouse();

	static void ProcessMouseEvents(GLFWwindow* window);

	static void SetMousePosition(GLFWwindow* window, double _x, double _y);

	static void GetMousePosition(GLFWwindow* window);

	static void GetMouseButtonState(GLFWwindow* window);

	static bool isLeftButtonPressed();

	static bool isRightButtonPressed();

private:

	static bool LeftButtonPressed;
	static bool RightButtonPressed;

	//position of the mouse
	static double x;
	static double y;
};

#endif // Mouse_h__
