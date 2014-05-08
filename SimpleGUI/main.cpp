#include "SimpleGUI.h"

#include "Button.h"
#include "RadioGroup.h"
#include "Slider.h"
#include "SpecialButton.h"
#include "Image.h"
#include "Font.h"
/*
The main function is for testing purposes only!

The main function is used to test the SimpleGUI library.
*/
int main()
{
	SimpleGUI gui;
	gui.InitWindow("SimpleGUI testwindow");

// 	RadioButton testButton(0, 0, 200, 100);
// 	RadioButton testButton2(150, 200, 50, 25);
// 
// 	RadioGroup group;

// 	group.AddElement(testButton);
// 	group.AddElement(testButton2);

/*	gui.AddElement(group);*/

/*	Slider testSlider(150, 200, 50, 25);*/

	//gui.AddElement(testSlider);

	//SpecialButton tempSpecialButton(100, 100, 50 , 50);
	//gui.AddElement(tempSpecialButton);

	gui.LoadFromXML("test.xml");

// 	Image test("res/cs_font.png" ,0 , 0);
// 	gui.AddElement(test);

	gui.WaitforEvents();
	
	return 0;
}