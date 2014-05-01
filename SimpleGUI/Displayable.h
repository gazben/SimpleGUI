#ifndef Displayable_h__
#define Displayable_h__

class Displayable
{
private:
	bool visible;

public:

	Displayable(){
		visible = true;
	}

	bool isVisible(){
		return visible;
	}
	virtual void Draw() = 0;
};

#endif // Displayable_h__
