#ifndef Character_h__
#define Character_h__

#include <FreeImage/FreeImage.h>

class Character{
public:

	Character(char _c);
	~Character();

	void setImage(FIBITMAP* image, int left, int top, int right, int bottom);

	void Draw(double pos_x, double pos_y);

	char getChar();

private:

	double height;
	double width;

	char* char_image;
	char represented_char;
};
#endif // Character_h__
