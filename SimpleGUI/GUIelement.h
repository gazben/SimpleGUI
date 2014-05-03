#ifndef GUIelement_h__
#define GUIelement_h__

struct GLFWwindow;

class GUIelement
{
protected:

	bool visible;

	double x;
	double y;
	double width;
	double height;

public:

	void SetPosition(double _x, double _y);
	void SetSize(double _width, double _height);

	bool isVisible();
	void SetVisible(bool _visible);

	virtual void Show() = 0;
	virtual void ProcessUserEvents(GLFWwindow*) = 0;

	virtual GUIelement* clone() const = 0;  // Virtual constructor for copying

};

#endif // GUIelement_h__
