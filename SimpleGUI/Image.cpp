#include "Image.h"

#define  GLFW_DLL
#include <GLFW/glfw3.h>

GUIelement* Image::clone() const
{
	return new Image(*this);
}

void Image::ProcessUserEvents(GLFWwindow*){
}

void Image::Show(){
	glRasterPos2i(x, y);
	glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels_raw);
}

void Image::Resize(int _width, int _height){
	FreeImage_Rescale(image, _width, _height);
	pixels_raw = (char*)FreeImage_GetBits(image);

	height = _height;
	width = _width;
}

void Image::Scale(double scale_ammount){
	height *= scale_ammount;
	width *= scale_ammount;

	FreeImage_Rescale(image, width, height, FILTER_BSPLINE);
	pixels_raw = (char*)FreeImage_GetBits(image);
}

Image::Image(std::string fileneame, float pos_x , float pos_y){
	image = FreeImage_Load(FIF_PNG, fileneame.c_str(), PNG_DEFAULT);
	image = FreeImage_ConvertTo32Bits(image);

	width = FreeImage_GetWidth(image);
	height = FreeImage_GetHeight(image);

	pixels_raw = (char*)FreeImage_GetBits(image);

	x = pos_x;
	y = pos_y;

	visible = true;
}

Image::~Image()
{
	delete this->image;
	delete[] pixels_raw;
}
