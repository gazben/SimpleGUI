#include "Slider.h"
#include "Mouse.h"
#include "Color.h"

#define GLEW_STATIC
#include <GL/glew.h>

#define  GLFW_DLL
#include <GLFW/glfw3.h>

#include <stdio.h>

GUIelement* Slider::clone() const
{
	return new Slider(*this);
}

void Slider::ProcessUserEvents(GLFWwindow* window){
	double Mouse_x = Mouse::GetPosition_x();
	double Mouse_y = Mouse::GetPosition_y();

	//we set the slider value to the right value. 
	if ((Mouse_y <= y + height) && (Mouse_y > y)
		&& (Mouse_x <= x + width) && (Mouse_x > x)){
		if (Mouse::getLeftButtonState() == MouseState::DOWN){
			if (horizontal){
				Slider_value = (Mouse_x - x) / (width);
			}
			else{
				Slider_value = (Mouse_y - y) / (height);
			}

#ifdef _DEBUG
			printf("Slider: %lf\n", Slider_value);
#endif // DEBUG
		}
	}
}

void Slider::Show(){
	//Draw the this is where the user can click
	glPushMatrix();

	glColor3f(Colors::blue.r, Colors::blue.g, Colors::blue.b);

	glBegin(GL_QUADS);

	glVertex2d(x, y);
	glVertex2d(x, y + height);
	glVertex2d(x + width, y + height);
	glVertex2d(x + width, y);

	glEnd();

	glPopMatrix();

	//Draw the slider indicator this will show "how far the process did go"
	double sliderSize_thick;

	if (horizontal){
		sliderSize_thick = width / 4.0;
	}
	else
	{
		sliderSize_thick = height / 7.5;
	}

	glPushMatrix();

	glColor3f(Colors::white.r, Colors::white.g, Colors::white.b);

	glBegin(GL_QUADS);

	if (horizontal){
		glVertex2d(x + (width * Slider_value) - sliderSize_thick * 0.5, y - sliderSize_thick * 0.5);
		glVertex2d(x + (width * Slider_value) - sliderSize_thick * 0.5, y + height + sliderSize_thick * 0.5);
		glVertex2d(x + (width * Slider_value) + sliderSize_thick * 0.5, y + height + sliderSize_thick * 0.5);
		glVertex2d(x + (width * Slider_value) + sliderSize_thick * 0.5, y - sliderSize_thick * 0.5);
	}
	else
	{
		glVertex2d(x - sliderSize_thick, y + (height * Slider_value) - sliderSize_thick * 0.5);
		glVertex2d(x + width + sliderSize_thick, y + (height * Slider_value) - sliderSize_thick * 0.5);
		glVertex2d(x + width + sliderSize_thick, y + (height * Slider_value) + sliderSize_thick * 0.5);
		glVertex2d(x - sliderSize_thick, y + (height * Slider_value) + sliderSize_thick * 0.5);
	}

	glEnd();

	glPopMatrix();
}

Slider::Slider(double _x, double _y, double _width, double _height, bool _horizontal /*= true*/)
{
	x = _x;
	y = _y;
	height = _height;
	width = _width;
	horizontal = _horizontal;
}

double Slider::getValue(){
	return Slider_value;
}