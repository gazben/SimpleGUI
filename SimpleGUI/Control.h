#ifndef Control_h__
#define Control_h__

#include "Displayable.h"

class Control :Displayable{

private:

	float x;
	float y;
	float width;
	float height;

public:
	virtual void ProcessUserEvents() = 0;

};

#endif // Control_h__
