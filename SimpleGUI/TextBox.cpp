#include "TextBox.h"
#include "Color.h"
#include "Slider.h"

#define GLEW_STATIC
#include <GL/glew.h>

#define GLFW_DLL
#include <GLFW/glfw3.h>

GUIelement* TextBox::clone() const{
	return new TextBox(*this);
}

void TextBox::ProcessUserEvents(GLFWwindow* window){
}

//Draws the textbox to the given coordinates with the right color
void TextBox::Show(){
	glColor4f(backGround.r, backGround.g, backGround.b, backGround.a);
	glBegin(GL_QUADS);
	//a rect for the box
	glVertex2f(x, y);
	glVertex2f(x, y + height);
	glVertex2f(x + width, y + height);
	glVertex2f(x + width, y);
	glEnd();

	double textpos_x = x;
	double textpos_y = y + height;

	//we put every letter a little further (character spacing)
	for (int i = 0; i < text.size(); i++){
		char c = text[i];

		glColor4f(textColor.r, textColor.g, textColor.b, textColor.a);
		font.DrawChar(c, textpos_x, textpos_y);

		textpos_x += 20;
	}
}

TextBox::TextBox(double _x, double _y, double _width, double _height){
	x = _x;
	y = _y;
	width = _width;
	height = _height;

	visible = true;

	backGround = Colors::blue;		//we init the colors
	textColor = Colors::green;

}

void TextBox::clear(){
	text.clear();
}

Color& TextBox::getBackgroundColor(){
	return backGround;
}

Color& TextBox::getTextColor(){
	return textColor;
}

void TextBox::setText(std::string _text)
{
	text = _text;
}