#include "Character.h"

#define  GLFW_DLL
#include <GLFW/glfw3.h>

void Character::Draw(double pos_x, double pos_y)
{
	if (!loaded){
		loadtexture();
		loaded = true;
	}
		

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, tex_ID);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(pos_x , pos_y);
	glTexCoord2f(0.0, 1.0); glVertex2f(pos_x, pos_y + height);
	glTexCoord2f(1.0, 1.0); glVertex2f(pos_x + width, pos_y + height);
	glTexCoord2f(1.0, 0.0); glVertex2f( pos_x + width, pos_y);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Character::setImage(FIBITMAP* image, int left, int top, int right, int bottom)
{
	height = top - bottom;
	width = right - left;

	FIBITMAP* temp = FreeImage_Copy(image, left, top, right, bottom);
	char_image = (char*)FreeImage_GetBits(temp);
}

Character::~Character(){
}

Character::Character(char _c, double _height, double _width){
	//hack sorry I had no time to redo the font image

	//upper character -> lower case
	if (_c <= 'Z'){
		_c = 'a' + (_c - 'A');
	}
	//lower case -> upper case
	else
	{
		_c = 'A' + (_c - 'a');
	}

	represented_char = _c;

	char_image = nullptr;
	height = _height;
	width = _width;

	loaded = false;
}

char Character::getChar(){
	return represented_char;
}

void Character::loadtexture()
{
	glGenTextures(1, &tex_ID);
	glBindTexture(GL_TEXTURE_2D, tex_ID);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, char_image);
}
