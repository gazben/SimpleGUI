#ifndef Character_h__
#define Character_h__

#define GLEW_STATIC
#include <GL/glew.h>

#define GLFW_DLL
#include <GLFW/glfw3.h>

#include <FreeImage/FreeImage.h>

class Character{
public:

	Character(char _c , double _width , double _height);
	~Character();

	void setImage(FIBITMAP* image, int left, int top, int right, int bottom);

	void Draw(double pos_x, double pos_y);

	char getChar();

private:

	double height;
	double width;

	char* char_image;
	char represented_char;

	bool loaded;

	void loadtexture();
	GLuint tex_ID;
};
#endif // Character_h__
