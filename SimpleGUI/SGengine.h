#ifndef SGengine_h__
#define SGengine_h__

#include <vector>

#include "Displayable.h"
#include "Control.h"

class SGengine{
public:

	void Show();
	void AddElement(Displayable);
	void AddElement(Control);

private:

	std::vector<Displayable*>	DisplayableElements;
	std::vector<Control*>		ControlElements;
};

#endif // SGengine_h__
