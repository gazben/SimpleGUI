#ifndef Font_h__
#define Font_h__

#include "Character.h"

#include <vector>

class Font{
public:

	Font();

	void DrawChar(char c);

private:

	std::vector<Character> characers_upper;
	std::vector<Character> characers_lower;
};

#endif // Font_h__
