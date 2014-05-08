#ifndef Font_h__
#define Font_h__

#include "Character.h"

#include <vector>

/*
Ths font will be used by the textbox gui element to drw and load buttons.
*/
class Font{
public:

	Font();

	void DrawChar(char c, double pos_x, double pos_y);		//draw a specified character to the given x,y position

private:

	std::vector<Character> characters;		//container for the characters
};

#endif // Font_h__
