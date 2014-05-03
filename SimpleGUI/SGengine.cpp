#include "SGengine.h"
#include "GUIelement.h"
#include "Mouse.h"
#include "Keyboard.h"

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

void SGengine::InitWindow(std::string title, int width, int height)
{
	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, Keyboard::KeyCallback);
	glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);
	glfwSetCursorPosCallback(window, Mouse::MousePosCallback);
}

SGengine::SGengine()
{
	glfwInit();
	window = nullptr;
}

void SGengine::WaitforEvents()
{

	while (!glfwWindowShouldClose(window))
	{
		HandleEvents();
		Show();
		
		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}

void SGengine::setMousePosition(double x, double y)
{
	Mouse::SetMousePosition(window, x, y);
}