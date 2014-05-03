#ifndef SGengine_h__
#define SGengine_h__

#include <vector>

#include "Control.h"
#include "Mouse.h"

class GUIelement;

class SGengine{
public:

	void HandleEvents();
	void Show();

	void AddElement(GUIelement&);

	void InitWindow(std::string, int height, int width);

	void WaitforEvents();

	void setMousePosition(double x, double y);

	SGengine();

private:

	std::vector<GUIelement*>	GUIelements;

	Mouse mouse;

	GLFWwindow* window;
};

#endif // SGengine_h__
