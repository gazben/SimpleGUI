#include "SGengine.h"
#include "GUIelement.h"

void SGengine::Show()
{
	for each (GUIelement* a in GUIelements){
		if (a->isVisible())
			a->Show();
	}
}

void SGengine::HandleEvents(){
}

void SGengine::AddElement(GUIelement& inElement){
	GUIelements.push_back(inElement.clone());
}

void SGengine::InitWindow(std::string title, int width, int height)
{
	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	glfwMakeContextCurrent(window);

	//FOR TESTING ONLY!
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}

SGengine::SGengine()
{
	glfwInit();
	window = nullptr;
}