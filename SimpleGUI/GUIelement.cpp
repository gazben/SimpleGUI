#include "GUIelement.h"

bool GUIelement::isVisible()
{
	return visible;
}

void GUIelement::SetPosition(double _x, double _y)
{
	x = _x;
	y = _y;
}

void GUIelement::SetSize(double _width, double _height)
{
	width = _width;
	height = _height;
}

void GUIelement::SetVisible(bool _visible)
{
	visible = _visible;
}


