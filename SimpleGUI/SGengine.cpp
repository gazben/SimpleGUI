#include "SGengine.h"
#include "GUIelement.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "XMLparser.h"

#include "Font.h"

#define GLEW_STATIC
#include <GL/glew.h>

#define GLFW_DLL
#include <GLFW/glfw3.h>

Font font;

void SGengine::Show()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (unsigned int i = 0; i < GUIelements.size(); i++){
		if (GUIelements[i]->isVisible())
			GUIelements[i]->Show();
	}

	font.DrawChar('d', 10, 10);
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

	glLoadIdentity();

	int Window_x;
	int Window_y;
	glfwGetWindowSize(window, &Window_x, &Window_y);

	glViewport(0, 0, Window_x, Window_y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, Window_x, 0, Window_y);
	glMatrixMode(GL_MODELVIEW);

	glDisable(GL_DEPTH_TEST);
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

SGengine::~SGengine()
{
	for (int i = 0; i < GUIelements.size(); i++){
		delete GUIelements[i];
	}
}

void SGengine::LoadFromXML(std::string path)
{
	XMLparser parser( this ,path);
}