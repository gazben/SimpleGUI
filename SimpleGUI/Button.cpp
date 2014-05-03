#include "Button.h"

#ifdef __gl_h_
printf("gl.h included");		//debug
#endif


#define GLEW_STATIC
#include <GL/glew.h>

Button::Button(std::string _text, double _x, double _y, double _width, double _height){

	text = _text;
	visible = true;
	x = _x;
	y = _y;
	height = _height;
	width = _width;

}

Button::Button(const Button& _inButton){

	text = _inButton.text;
	visible = _inButton.visible;
	x = _inButton.x;
	y = _inButton.y;
	height = _inButton.height;
	width = _inButton.width;
}

void Button::Show(){
	
	glPushMatrix();

	glColor3d(0.5, 0.5, 0.5);

	glBegin(GL_QUADS);

	glVertex2d( x, y);
	glVertex2d( x, y + width);
	glVertex2d( x + height, y + width);
	glVertex2d( x + height, y );

	glEnd();

	glPopMatrix();

}

bool Button::isClicked(){
	return clicked;
}

GUIelement* Button::clone() const
{
	return new Button(*this);
}

void Button::ProcessUserEvents(GLFWwindow*)
{

}



