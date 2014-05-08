#include "XMLparser.h"
#include "SGengine.h"

#include "Button.h"
#include "RadioGroup.h"
#include "SpecialButton.h"
#include "TextBox.h"
#include "Slider.h"

#include <TINYXML/tinyxml2.h>

#include <iostream>

using namespace tinyxml2;

XMLparser::XMLparser(SGengine* _engine, std::string pathname){
	engine = _engine;

	tinyxml2::XMLDocument doc;

	if (doc.LoadFile((".\\" + pathname).c_str()) != 0){
		printf("LoadFile error!");
	}
	else{
		printf("read success");

		//feeling past midnight: http://www.youtube.com/watch?v=BVWfqOSdzs4

		std::string TypeName;
		double width;
		double height;
		double x;
		double y;

		XMLNode *root = doc.FirstChild()->NextSibling()->FirstChild();
		XMLNode *element = root;

		while ((element) != nullptr){
			TypeName = element->FirstChildElement("TypeName")->GetText();

//////////////////////////////////////////////////////////////////////////
// RadioButton 
//////////////////////////////////////////////////////////////////////////
			if (TypeName == "Button")
			{
				x = atof((element->FirstChildElement("x")->GetText()));
				y = atof((element->FirstChildElement("y")->GetText()));
				width = atof((element->FirstChildElement("width")->GetText()));
				height = atof((element->FirstChildElement("height")->GetText()));

				RadioButton gui_element(x, y, width, height);
				engine->AddElement(gui_element);
			}
//////////////////////////////////////////////////////////////////////////
// RadioGroup 
//////////////////////////////////////////////////////////////////////////
			else if (TypeName == "RadioGroup")
			{
				RadioGroup gui_element;

				XMLNode *RadioGroupNode = element->FirstChild()->NextSibling();

				while (RadioGroupNode != nullptr)
				{
					x = atof((RadioGroupNode->FirstChildElement("x")->GetText()));
					y = atof((RadioGroupNode->FirstChildElement("y")->GetText()));
					width = atof((RadioGroupNode->FirstChildElement("width")->GetText()));
					height = atof((RadioGroupNode->FirstChildElement("height")->GetText()));

					RadioButton radio(x, y, width, height);

					gui_element.AddElement(radio);

					RadioGroupNode = RadioGroupNode->NextSibling();
				}

				engine->AddElement(gui_element);
			}
//////////////////////////////////////////////////////////////////////////
// SpecialButton 
//////////////////////////////////////////////////////////////////////////
			else if (TypeName == "SpecialButton")
			{
				x = atof((element->FirstChildElement("x")->GetText()));
				y = atof((element->FirstChildElement("y")->GetText()));
				width = atof((element->FirstChildElement("width")->GetText()));
				height = atof((element->FirstChildElement("height")->GetText()));

				SpecialButton gui_element(x, y, width, height);
				engine->AddElement(gui_element);
			}
//////////////////////////////////////////////////////////////////////////
// TextBox
//////////////////////////////////////////////////////////////////////////
			else if (TypeName == "TextBox")
			{
				x = atof((element->FirstChildElement("x")->GetText()));
				y = atof((element->FirstChildElement("width")->GetText()));
				width = atof((element->FirstChildElement("y")->GetText()));
				height = atof((element->FirstChildElement("height")->GetText()));

				TextBox gui_element(x, y, width, height);
				engine->AddElement(gui_element);
			}
//////////////////////////////////////////////////////////////////////////
// Slider
//////////////////////////////////////////////////////////////////////////
			else if (TypeName == "Slider")
			{
				x = atof((element->FirstChildElement("x")->GetText()));
				y = atof((element->FirstChildElement("y")->GetText()));
				width = atof((element->FirstChildElement("width")->GetText()));
				height = atof((element->FirstChildElement("height")->GetText()));

				Slider gui_element(x, y, width, height);
				engine->AddElement(gui_element);
			}

			element = root->NextSibling();
		}
	}
}