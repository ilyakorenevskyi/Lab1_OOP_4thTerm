#pragma once
struct line;
struct circle;
#include <cmath>
#include <iostream>
#include "Figure.h"
using namespace std;
class point : public Figure {
	double x, y;
public:
	point();
	point(double x, double y);
	point(line l1, line l2);
	double getX();
	double getY();
	void output();
	point* reflect(line a) ;
	point* invert(circle a) ;
	friend bool operator<(point& a, point& b);
	friend bool operator>(point& a, point& b);
	friend bool operator<=(point& a, point& b);
	friend bool operator>=(point& a, point& b);
	friend bool operator==(point& a, point& b);
	friend bool operator!=(point& a, point& b);
	friend std::istream& operator>>(std::istream& cin, point& p);
	friend std::ostream& operator<<(std::ostream& cout, point& p);

};

