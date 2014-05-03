#include "SGengine.h"
#include "GUIelement.h"

#include "Mouse.h"

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

	//FOR TESTING ONLY!
// 	while (!glfwWindowShouldClose(window))
// 	{
// 		glfwSwapBuffers(window);
// 
// 		glfwPollEvents();
// 	}
}

SGengine::SGengine()
{
	glfwInit();
	window = nullptr;
}