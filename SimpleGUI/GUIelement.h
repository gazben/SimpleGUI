#ifndef GUIelement_h__
#define GUIelement_h__

struct GLFWwindow;

/*
Base class for the gui elements that will be drawn on the screen.
*/
class GUIelement
{
protected:

	bool visible;		//true if the gui element is visible

	/*
	position data
	*/
	double x;
	double y;
	double width;
	double height;

public:

	void SetPosition(double _x, double _y);		//set the x,y position of the element
	void SetSize(double _width, double _height);	//set the size of the element

	bool isVisible();			//returns true if the element is visible
	void SetVisible(bool _visible);

	virtual void Show() = 0;		
	virtual void ProcessUserEvents(GLFWwindow*) = 0;

	virtual GUIelement* clone() const = 0;  // Virtual constructor for copying

};

#endif // GUIelement_h__
