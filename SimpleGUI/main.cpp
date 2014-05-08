#include "SimpleGUI.h"

#include "Button.h"
#include "RadioGroup.h"
#include "Slider.h"
#include "SpecialButton.h"
#include "Image.h"
#include "Font.h"
#include "TextBox.h"

#include <stdio.h>

/*
The main function is for testing purposes only!

The main function is used to test the SimpleGUI library.
*/

int main()
{
	SimpleGUI gui;
	gui.InitWindow("SimpleGUI testwindow", 800, 600);

	SpecialButton clearButton(50, 200, 30, 30);
	TextBox text(300, 100, 100, 100);
	text.setText("proba");
	//clearButton.SetButtonDoneCallback(text.clear);

	Image background( "background.png", 100 , 100 );
	gui.AddElement(background);

	Slider r(40 , 30 , 60 , 15);
	Slider g(40, 70, 60, 15);
	Slider b(40, 110, 60, 15);
	Slider a(40, 150, 60, 15);

	RadioGroup group;

	RadioButton button1(130 , 90 , 30 , 25);
	RadioButton button2(130 , 130 , 30 , 25);

	group.AddElement(button1);
	group.AddElement(button2);

	gui.AddElement(group);

	gui.AddElement(r);
	gui.AddElement(g);
	gui.AddElement(b);
	gui.AddElement(a);

	gui.AddElement(text);
	gui.AddElement(clearButton);

	gui.WaitforEvents();

	return 0;
}