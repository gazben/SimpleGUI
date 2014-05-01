#ifndef GUIelement_h__
#define GUIelement_h__

class GUIelement
{
private:
	bool visible;

	float x;
	float y;
	float width;
	float height;

public:

	GUIelement(){
		visible = true;
	}

	bool isVisible(){
		return visible;
	}
	virtual void Show() = 0;
	virtual void ProcessUserEvents() = 0;
};

#endif // GUIelement_h__
