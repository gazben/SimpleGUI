#include "Character.h"

#define  GLFW_DLL
#include <GLFW/glfw3.h>

void Character::Draw(double pos_x, double pos_y)
{

	glRasterPos2i(pos_x, pos_y);
	glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, char_image);
}

void Character::setImage(FIBITMAP* image, int left, int top, int right, int bottom)
{
	height = top - bottom;
	width = right - left;

	FIBITMAP* temp = FreeImage_Copy(image, left, top, right, bottom);
	char_image = (char*)FreeImage_GetBits(temp);
}

Character::~Character(){
	//TODO - WTF??? if you uncomment this it will throw a debug assertion at you
// 	if( char_image != nullptr )
// 		delete char_image;
}

Character::Character(char _c){
	represented_char = _c;

	char_image = nullptr;
}

char Character::getChar(){
	return represented_char;
}