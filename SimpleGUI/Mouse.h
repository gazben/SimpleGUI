#ifndef Mouse_h__
#define Mouse_h__

struct GLFWwindow;

enum MouseState{
	DOWN,
	UP,
	HELD
};

class Mouse{
public:

	Mouse();

	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	static void MousePosCallback(GLFWwindow * window, double _x, double _y);

	static void SetMousePosition(GLFWwindow* window, double _x, double _y);

	static double GetPosition_x();
	static double GetPosition_y();

	static MouseState getLeftButtonState();
	static MouseState getRightButtonState();

	static bool isClickLeft(GLFWwindow* window);

private:

	//status of the buttons
	static MouseState LeftButtonState;
		static MouseState LeftButtonState_last;
	static MouseState RightButtonState;
		static MouseState RightButtonState_last;

	//position of the mouse
	static double x;
	static double y;

};

#endif // Mouse_h__
