#include "SpecialButton.h"
#include "Color.h"
#include "Mouse.h"

#include <math.h>
#define GLEW_STATIC
#include <GL/glew.h>

#include <stdio.h>

#define  GLFW_DLL
#include <GLFW/glfw3.h>

#define PI 3.14159265

GUIelement* SpecialButton::clone() const
{
	return new SpecialButton(*this);
}

void SpecialButton::ProcessUserEvents(GLFWwindow* window){
	double mouse_x = Mouse::GetPosition_x();
	double mouse_y = Mouse::GetPosition_y();

	double center_x = x + height / 2.0;
	double center_y = y + height / 2.0;

	double dist = sqrt(pow(mouse_x - center_x, 2) + pow(mouse_y - center_y, 2));

	if (dist <= height / 2.0){
		//mouse is on the button
		if (Mouse::getLeftButtonState() == MouseState::DOWN){
			if (!pressed){
				clicked_time = glfwGetTime();
				pressed = true;
			}

			double time_elapsed = glfwGetTime() - clicked_time;

			double completed_distance = ((2 * PI * (height / 2.0)) / 2.0) * time_elapsed;

			Button_value = completed_distance / (2 * PI * (height / 2.0));		//megtett �t / �ssz �t

			printf("Button value: %lf  TimeElapsed: %lf\n", Button_value, time_elapsed);

			if (time_elapsed >= 2.0){
				Button_value = 0;
				clicked_time = glfwGetTime();
			}
		}
		else{
			Button_value = 0;
			pressed = false;
		}
	}
}

void SpecialButton::Show()
{
	//first we draw the button
	glBegin(GL_TRIANGLE_FAN);
	float radius = height / 2.0, center_x = x + radius, center_y = y + radius;

	glColor3f(Colors::green.r, Colors::green.g, Colors::green.b);

	glVertex2f(center_x, center_y);

	for (int i = 0; i <= 64; i++) {
		float angle = float(i) / 64 * 2.0f * PI;
		glVertex2f(center_x + radius*cos(angle), center_y + radius*sin(angle));
	}
	glEnd();
}

SpecialButton::SpecialButton(double _x, double _y, double _width, double _height){
	height = _height;
	width = _width;

	x = _x;
	y = _y;

	pressed = false;
	clicked_time = 0;
	Button_value = 0;
}