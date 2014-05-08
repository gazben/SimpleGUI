#ifndef Image_h__
#define Image_h__

#include "GUIelement.h"

#include <FreeImage/FreeImage.h>
#include <string>
/*
Represents an image that can be drawn on screen
*/
class Image :public GUIelement{
public:

	Image(std::string fileneame, float pos_x, float pos_y);
	~Image();

	virtual void Show();		//draw the image

	virtual void ProcessUserEvents(GLFWwindow*);

	virtual GUIelement* clone() const;

	void Resize(int _width, int _height);		
	void Scale(double scale_ammount);
private:

	FIBITMAP* image;	
	char* pixels_raw;
	int width;
	int height;
};

#endif // Image_h__
