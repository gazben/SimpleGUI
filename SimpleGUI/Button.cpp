#include "Button.h"

void Button::ProcessUserEvents(){

}

void Button::Show(){

}

bool Button::isClicked(){
	return clicked;
}

GUIelement* Button::clone() const
{
	return new Button(*this);
}
