#include "Slider.h"
#include "Mouse.h"
#include "Color.h"

#ifdef __gl_h_
printf("gl.h included");	//for debug (don't mess with the includes!)
#endif

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

	if ((Mouse_y <= y + height) && (Mouse_y > y)
		&& (Mouse_x <= x + width) && (Mouse_x > x)){
		if (Mouse::getLeftButtonState() == MouseState::DOWN){
			if (horizontal){
				Slider_value = (Mouse_x - x) / (width);
			}
			else{
				Slider_value = (Mouse_y - y) / (height);
			}
			printf("Slider: %lf\n", Slider_value);
		}
	}
}

void Slider::Show(){
	//Draw a rect
	glPushMatrix();

	glColor3f(Colors::blue.r, Colors::blue.g, Colors::blue.b);

	glBegin(GL_QUADS);

	glVertex2d(x, y);
	glVertex2d(x, y + height);
	glVertex2d(x + width, y + height);
	glVertex2d(x + width, y);

	glEnd();

	glPopMatrix();

	//Draw the slider indicator
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
		glVertex2d(x + (width * Slider_value) - sliderSize_thick * 0.5, y - sliderSize_thick);
		glVertex2d(x + (width * Slider_value) - sliderSize_thick * 0.5, y + height + sliderSize_thick);
		glVertex2d(x + (width * Slider_value) + sliderSize_thick * 0.5, y + height + sliderSize_thick);
		glVertex2d(x + (width * Slider_value) + sliderSize_thick * 0.5, y - sliderSize_thick);
	}

	glEnd();

	glPopMatrix();
}