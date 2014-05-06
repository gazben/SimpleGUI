#include "Button.h"
#include "Mouse.h"
#include "Color.h"

#ifdef _DEBUG
#include <stdio.h>
#endif

#ifdef __gl_h_
printf("gl.h included");
#endif

#define GLEW_STATIC
#include <GL/glew.h>

#define  GLFW_DLL
#include <GLFW/glfw3.h>

RadioButton::RadioButton(std::string _text, double _x, double _y, double _width, double _height){
	text = _text;
	visible = true;
	x = _x;
	y = _y;
	height = _height;
	width = _width;
}

RadioButton::RadioButton(const RadioButton& _inButton){
	text = _inButton.text;
	visible = _inButton.visible;
	x = _inButton.x;
	y = _inButton.y;
	height = _inButton.height;
	width = _inButton.width;
}

void RadioButton::Show(){
	glPushMatrix();

	if (clicked)
		glColor3f(Colors::green.r, Colors::green.g, Colors::green.b);
	else
		glColor3f(Colors::blue.r, Colors::blue.g, Colors::blue.b);

	glBegin(GL_QUADS);

	glVertex2d(x, y);
	glVertex2d(x, y + height);
	glVertex2d(x + width, y + height);
	glVertex2d(x + width, y);

	glEnd();

	glPopMatrix();
}

bool RadioButton::isClicked(){
	return clicked;
}

GUIelement* RadioButton::clone() const
{
	return new RadioButton(*this);
}

void RadioButton::ProcessUserEvents(GLFWwindow* window){
	double Mouse_x = Mouse::GetPosition_x();
	double Mouse_y = Mouse::GetPosition_y();

	if ((Mouse_y <= y + height) && (Mouse_y > y)
		&& (Mouse_x <= x + width) && (Mouse_x > x)){
		//Mouse is crossing the button (possible feature here

		if (Mouse::isClickLeft(window)){
			clicked = !clicked;

			timeClicked = glfwGetTime();
#ifdef _DEBUG
			printf("Button has been clicked!\n");
#endif
		}
	} // crossing if end
}	// ProcessUserEvents function end

double RadioButton::getTimeClicked(){
	return timeClicked;
}

//we can set manually a buttons state
void RadioButton::setClicked(bool _clicked){
	clicked = _clicked;
}
