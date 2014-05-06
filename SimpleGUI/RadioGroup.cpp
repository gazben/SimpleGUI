#include "RadioGroup.h"

#include "Button.h"

//we deep clone the object (so we can add it to the GUIelements list)
GUIelement* RadioGroup::clone() const{
	return new RadioGroup(*this);
}

void RadioGroup::ProcessUserEvents(GLFWwindow* window){
	for (unsigned int i = 0; i < RadioButtons.size(); i++){		//first we update the buttons (to get the right time values
		RadioButtons[i].ProcessUserEvents(window);
	}

	if (!RadioButtons.empty()){		//we don't want to check on an empty collection
		double maxClickedTime = RadioButtons[0].getTimeClicked();	//max search for the last clicked element
		int maxIndex = 0;			//index of the last clicked element

		if (RadioButtons.size() > 0){
			for (unsigned int i = 1; i < RadioButtons.size(); i++){
				if (RadioButtons[i].getTimeClicked() > maxClickedTime){
					maxClickedTime = RadioButtons[i].getTimeClicked();
					maxIndex = i;
				}
			}	//max search for end
		}	//size > 0 if end

		for (unsigned int i = 0; i < RadioButtons.size(); i++){
			if (i != maxIndex){
				RadioButtons[i].setClicked(false);	//we unclick the buttons
			}
		}
	}	//emprty if end
}//processUserEvents function end

void RadioGroup::Show()	{
	if (visible)
	{
		for (unsigned int i = 0; i < RadioButtons.size(); i++){
			RadioButtons[i].Show();
		}
	}
}

RadioGroup::RadioGroup(){
	//FIXME: Possible feature: give a group a global offset so they can be a real "group"
	x = 0;
	y = 0;
	width = 0;
	height = 0;

	visible = true;
}

void RadioGroup::AddElement(RadioButton& _inElement){
	RadioButtons.push_back(RadioButton(_inElement));
}