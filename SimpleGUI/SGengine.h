#ifndef SGengine_h__
#define SGengine_h__

#include <vector>

#define GLFW_DLL 
#include <GLFW/glfw3.h>

#include "GUIelement.h"
#include "Control.h"
#include "Mouse.h"

class SGengine{
public:

	void HandleEvents();
	void Show();

	void AddElement(GUIelement*);

	void InitWindow(std::string, int height, int width);

	SGengine();

private:

	std::vector<GUIelement*>	GUIelements;

	Mouse mouse;

	GLFWwindow* window;
};

#endif // SGengine_h__
