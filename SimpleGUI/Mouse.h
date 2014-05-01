#ifndef Mouse_h__
#define Mouse_h__

#include <GLFW/glfw3.h>

struct Mouse{

	bool LeftButton;
	bool RightButton;


	Mouse(){
		LeftButton = false;
		RightButton = false;
	}


	void ProcessMouseEvents(){
	
		
	}

};

#endif // Mouse_h__
