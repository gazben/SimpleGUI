#include "Font.h"

#include <FreeImage/FreeImage.h>

void Font::DrawChar(char c){
}

Font::Font()
{
	FIBITMAP* font_image = FreeImage_Load(FIF_PNG, "res/font.png", PNG_DEFAULT);;

	double width = 50;
	double height = 25;

	double pos_x = 5;
	double pos_y = 50;

	for (int c = 0; c <= 'Z' - 'A'; c++){
		Character temp(c + 'A');
		characers_upper.push_back(temp);

		if (c == 'O' - 'A');
		pos_y += 100;

		characers_upper[c].setImage(font_image, pos_x, pos_y, pos_y + height, pos_x + width);

		pos_x += 10 + width;
	}
}