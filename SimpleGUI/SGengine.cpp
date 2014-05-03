#include "SGengine.h"
#include "GUIelement.h"

#include "Mouse.h"
#include "Keyboard.h"

#include <stdio.h>
#define GLFW_DLL
#include <GLFW/glfw3.h>

void SGengine::Show()
{
	for (unsigned int i = 0; i < GUIelements.size(); i++){
		if (GUIelements[i]->isVisible())
			GUIelements[i]->Show();
	}
}

void SGengine::HandleEvents(){
	for (unsigned int i = 0; i < GUIelements.size(); i++){
		GUIelements[i]->ProcessUserEvents(window);
	}
}

void SGengine::AddElement(GUIelement& inElement){
	GUIelements.push_back(inElement.clone());
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void SGengine::InitWindow(std::string title, int width, int height)
{
	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, Keyboard::KeyCallback);
}

SGengine::SGengine()
{
	glfwInit();
	window = nullptr;
}

void SGengine::WaitforEvents()
{
	//FOR TESTING ONLY!
	while (!glfwWindowShouldClose(window))
	{
		printf("%lf\n", glfwGetTime());

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}

void SGengine::setMousePosition(double x, double y)
{
	Mouse::SetMousePosition(window, x, y);
}
