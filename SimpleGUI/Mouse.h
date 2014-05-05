#ifndef Mouse_h__
#define Mouse_h__

struct GLFWwindow;

class Mouse{
public:

	Mouse();

	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	static void MousePosCallback(GLFWwindow * window, double _x, double _y);

	static void SetMousePosition(GLFWwindow* window, double _x, double _y);

	static double GetPosition_x();
	static double GetPosition_y();

	static bool isLeftButtonPressed();
	static bool isRightButtonPressed();

private:

	static int LeftButtonPressed;
	static int RightButtonPressed;

	//position of the mouse
	static double x;
	static double y;
};

#endif // Mouse_h__
