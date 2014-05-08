#include "Font.h"

#include <FreeImage/FreeImage.h>

int getCharNumber(char _c){
	return (_c <= 'Z' ? (int)_c - 'A' : (int)_c - 'a' + ('z' - 'a'));
}

void Font::DrawChar(char c, double pos_x, double pos_y){

	int index = c <= 'Z' ? (int)c - 'A' + ('z' - 'a') : (int)c - 'a';

	characters[index].Draw(pos_x, pos_y);

}

Font::Font()
{
	FIBITMAP* font_image = FreeImage_Load(FIF_PNG, ".\\res\comic_sans.png", PNG_DEFAULT);
	font_image = FreeImage_ConvertTo32Bits(font_image);

	double width = 16;
	double height = 33;

	double pos_x;

	for (char c = 'A'; c <= 'z'; c++){
		Character temp(c, width, height);
		characters.push_back(temp);

		pos_x = width * getCharNumber(c) + 5;

		characters[getCharNumber(c)].setImage(font_image, pos_x, 0, pos_x + width, height);

		if (c == 'Z')
			c = 'a' - 1;
	}

	image = (char*)FreeImage_GetBits(font_image);



}