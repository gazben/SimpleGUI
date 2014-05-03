#include "SimpleGUI.h"

#include "Button.h"
/*
The main function is for testing purposes only!

The main function is used to test the SimpleGUI library.
*/
int main()
{
	SimpleGUI gui;
	gui.InitWindow("SimpleGUI testwindow");

	Button testButton("test", 100 , 100 , 20 , 10);

	gui.AddElement(testButton);

	gui.WaitforEvents();
	// 	GLFWwindow* window;
	//
	// 	/* Initialize the library */
	// 	if (!glfwInit())
	// 		return -1;
	//
	// 	/* Create a windowed mode window and its OpenGL context */
	// 	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	// 	if (!window)
	// 	{
	// 		glfwTerminate();
	// 		return -1;
	// 	}
	//
	// 	/* Make the window's context current */
	// 	glfwMakeContextCurrent(window);
	//
	// 	/* Loop until the user closes the window */
	// 	while (!glfwWindowShouldClose(window))
	// 	{
	// 		/* Render here */
	//
	// 		/* Swap front and back buffers */
	// 		glfwSwapBuffers(window);
	//
	// 		/* Poll for and process events */
	// 		glfwPollEvents();
	// 	}
	//
	// 	glfwTerminate();

	return 0;
}