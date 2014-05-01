#ifndef SimpleGUI_h__
#define SimpleGUI_h__

#include <string>

#include "GUIelement.h"
#include "Control.h"
#include "SGengine.h"

/*
class SimpleGUI: this class is an interface between the SGengine and the user.

This way we define an interface and the whole engine is replaceable.
*/

class SimpleGUI{
public:

	//Initialise the gui
	void Init( std::string , int height = 800, int width = 600);	//init without xml
	void Init(std::string);		//init from xml

	void setMousePosition();
	void setKeyState();

	//Add a drawable element to the gui.
	void AddElement(GUIelement&);

	//Handle the events from the user. Ex.: Mouse
	void HandleEvents();

	//Show the gui on the screen
	void Show();

	SimpleGUI(){
		shouldClose = false;
	}

private:

	bool shouldClose;

	SGengine engine;
};
#endif // SimpleGUI_h__
