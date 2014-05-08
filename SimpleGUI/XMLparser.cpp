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

			if (TypeName == "Button")
			{
				x = atof((element->FirstChildElement("x")->GetText()));
				y = atof((element->FirstChildElement("y")->GetText()));
				width = atof((element->FirstChildElement("y")->GetText()));
				height = atof((element->FirstChildElement("height")->GetText()));

				RadioButton gui_element(x, y, width, height);
				engine->AddElement(gui_element);
			}
			else if (TypeName == "RadioGroup")
			{
				RadioGroup gui_element;

				XMLNode *RadioGroupNode = element->FirstChild();

				while (RadioGroupNode != nullptr)
				{
					x = atof((element->FirstChildElement("x")->GetText()));
					y = atof((element->FirstChildElement("y")->GetText()));
					width = atof((element->FirstChildElement("y")->GetText()));
					height = atof((element->FirstChildElement("height")->GetText()));

					RadioButton radio(x, y, width, height);

					gui_element.AddElement(radio);

					RadioGroupNode = RadioGroupNode->NextSibling();
				}

				engine->AddElement(gui_element);
			}
			else if (TypeName == "SpecialButton")
			{
				x = atof((element->FirstChildElement("x")->GetText()));
				y = atof((element->FirstChildElement("y")->GetText()));
				width = atof((element->FirstChildElement("y")->GetText()));
				height = atof((element->FirstChildElement("height")->GetText()));
			}
			else if (TypeName == "TextBox")
			{
				x = atof((element->FirstChildElement("x")->GetText()));
				y = atof((element->FirstChildElement("y")->GetText()));
				width = atof((element->FirstChildElement("y")->GetText()));
				height = atof((element->FirstChildElement("height")->GetText()));
			}
			else if (TypeName == "Slider")
			{
				x = atof((element->FirstChildElement("x")->GetText()));
				y = atof((element->FirstChildElement("y")->GetText()));
				width = atof((element->FirstChildElement("y")->GetText()));
				height = atof((element->FirstChildElement("height")->GetText()));
			}

			element = root->NextSibling();
		}
	}
}