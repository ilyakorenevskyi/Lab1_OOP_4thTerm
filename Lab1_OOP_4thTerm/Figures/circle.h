#pragma once
#include "Figure.h"
struct point;
#include <iostream>
#include "point.h"
class circle : public Figure {
	point center;
	double rad;
public:
	circle();
	circle(point c, double r);
	void setRadius(double rad);
	void setCenter(point center);
	double getRad();
	point getCenter();
	circle* reflect(line a);
	Figure* invert(circle a)  override;
	bool checkPoint(point to_check);
	void output();
	friend bool operator<(circle& a, circle& b);
	friend bool operator>(circle& a, circle& b);
	friend bool operator<=(circle& a, circle& b);
	friend bool operator>=(circle& a, circle& b);
	friend bool operator==(circle& a, circle& b);
	friend bool operator!=(circle& a, circle& b);
	friend std::ostream& operator<< (std::ostream& cout, circle& c);
	friend std::istream& operator>>(std::istream& cin, circle& c);
};

