#ifndef Character_h__
#define Character_h__

#define GLEW_STATIC
#include <GL/glew.h>

#define GLFW_DLL
#include <GLFW/glfw3.h>

#include <FreeImage/FreeImage.h>

/*
This class represent a character that will be drawn on the screen.
*/
class Character{
public:

	Character(char _c , double _width , double _height);

	void setImage(FIBITMAP* image, int left, int top, int right, int bottom);	//set the character image this will be displyed FIXME

	void Draw(double pos_x, double pos_y);		//displays the character on the screen

	char getChar();		//returns the represented character of the object

private:

	
	double height;	//draw height
	double width;	//draw width

	char* char_image;	//pointer to the texture data that will be drawn
	char represented_char;	//represented character of the object

	bool loaded;		//true if the texture data has been loaded on the gpu

	void loadtexture();		//loads the texture to the gpu
	GLuint tex_ID;		//texture id for the opengl call
};
#endif // Character_h__
