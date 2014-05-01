#include "SGengine.h"

void SGengine::Show()
{
	for each (GUIelement a in GUIelements){
		if (a.isVisible())
			a.Show();
	}
}
