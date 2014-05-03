#ifndef SimpleGUI_h__
#define SimpleGUI_h__

#include <string>

#include "SGengine.h"

class GUIelement;

/*
class SimpleGUI: this class is an interface between the SGengine and the user.

This way we define an interface and the whole engine is replaceable.
*/

class SimpleGUI{
public:

	//Initialise the gui
	void InitWindow( std::string , int height = 800, int width = 600);	//init without xml

	void LoadFromXML(std::string);

	void setMousePosition( double x , double y );
	void setKeyState();

	//Add a drawable element to the gui.
	void AddElement(GUIelement&);

	//Handle the events from the user. Ex.: Mouse
	void WaitforEvents();

	SimpleGUI(){
		shouldClose = false;
	}

private:

	bool shouldClose;

	SGengine engine;
};
#endif // SimpleGUI_h__
