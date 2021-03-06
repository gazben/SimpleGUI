#ifndef Color_h__
#define Color_h__

struct Color {
	float r, g, b, a;

	Color() {
		r = g = b = a = 0;
	}
	Color(float r0, float g0, float b0, float a0 = 1) {
		r = r0; g = g0; b = b0; a = a0;
	}
	Color operator*(float a) {
		return Color(r * a, g * a, b * a);
	}
	Color operator*(const Color& c) {
		return Color(r * c.r, g * c.g, b * c.b);
	}
	Color operator/(const Color& c) {
		return Color(r / c.r, g / c.g, b / c.b);
	}
	Color operator+(const Color& c) {
		return Color(r + c.r, g + c.g, b + c.b);
	}
	Color operator-(const Color& c) {
		return Color(r - c.r, g - c.g, b - c.b);
	}
	float operator[](int index){
		switch (index){
		case 0:
			return r;
		case 1:
			return g;
		case 2:
			return b;
		case 3:
			return a;

		default:
			return 0;
		}
	}
};

namespace Colors{
	static Color red(255.0f / 255.0f, 59.0f / 255.0f, 20.0f / 255.0f);
	static Color grey(196.0f / 255.0f, 196.0f / 255.0f, 196.0f / 255.0f);
	static Color blue(79.0f / 255.0f, 128.0f / 255.0f, 253.0f / 255.0f);
	static Color green(71.0f / 255.0f, 201.0f / 255.0f, 68.0f / 255.0f);
	static Color purple(87.0f / 255.0f, 144.0f / 255.0f, 18.0f / 255.0f);
	static Color white(1.0f, 1.0f, 1.0f);
	static Color black(0.01f, 0.01f, 0.01f);
}

#endif // Color_h__