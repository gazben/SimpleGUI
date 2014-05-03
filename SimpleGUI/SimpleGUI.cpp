#include "SimpleGUI.h"

void SimpleGUI::InitWindow(std::string title, int height /*= 800*/, int width /*= 600*/)
{
	engine.InitWindow(title, height, width);
}

void SimpleGUI::LoadFromXML(std::string){
}

void SimpleGUI::setMousePosition(double x, double y){
	engine.setMousePosition(x, y);
}

void SimpleGUI::setKeyState()
{
}

void SimpleGUI::AddElement(GUIelement& _element){
	engine.AddElement(_element);
}

void SimpleGUI::WaitforEvents(){
	engine.WaitforEvents();
}