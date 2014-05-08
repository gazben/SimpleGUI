#include "TextBox.h"
#include "Color.h"


#define GLEW_STATIC
#include <GL/glew.h>

#define GLFW_DLL
#include <GLFW/glfw3.h>

GUIelement* TextBox::clone() const
{
	return new TextBox(*this);
}

void TextBox::ProcessUserEvents(GLFWwindow* window){

}

void TextBox::Show(){

	glColor4f(backGround.r, backGround.g, backGround.b, backGround.a);
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x, y + height);
	glVertex2f(x + width, y + height);
	glVertex2f(x + width, y);
	glEnd();

	double textpos_x = x;
	double textpos_y = y + height;

	for (int  i = 0; i < text.size(); i++){
		char c = text[i];

		glColor4f(textColor.r, textColor.g, textColor.b, textColor.a);
		font.DrawChar(c, textpos_x, textpos_y);

		textpos_x += 20;
	}

}

TextBox::TextBox(double _x, double _y, double _width, double _height)
{
	x = _x;
	y = _y;
	width = _width;
	height = _height;

	text = "proba";

	visible = true;

	backGround = Colors::blue;
	textColor = Colors::green;
}
