#ifndef SimpleGUI_h__
#define SimpleGUI_h__

#include <string>

#include "Mouse.h"
#include "Displayable.h"

class SimpleGUI{
public:

	void InitfromXML(std::string path);

	void setMousePosition();
	void setKeyState();

	//Add a drawable element to the gui.
	void AddElement(Displayable);

	//Handle the events from the user. Ex.: Mouse
	void HandleEvents();

	//Show the gui on the screen
	void Show();

	SimpleGUI(){}

private:
	Mouse mouse;



};
#endif // SimpleGUI_h__
