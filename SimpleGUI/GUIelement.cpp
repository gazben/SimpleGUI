#include "GUIelement.h"

bool GUIelement::isVisible()
{
	return visible;
}

GUIelement::GUIelement()
{
	visible = true;
}