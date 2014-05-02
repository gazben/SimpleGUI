#include "SGengine.h"

void SGengine::Show()
{
	for each (GUIelement* a in GUIelements){
		if (a->isVisible())
			a->Show();
	}
}

void SGengine::HandleEvents()
{
}

void SGengine::AddElement(GUIelement* inElement)
{
}

void SGengine::InitWindow(std::string title, int width, int height)
{
	glfwInit();

	window = glfwCreateWindow(width, height, "szar", NULL, NULL);

	glfwMakeContextCurrent(window);

}