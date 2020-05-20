#pragma once
struct circle;
#include "Figure.h"
#include "circle.h"
#include <iostream>
class line : public Figure {
	double k;
	double b;
public:
	line(double k, double b);
	line();
	double getK();
	double getB();
	friend bool operator<(line& a, line& b);
	friend bool operator>(line& a, line& b);	
	friend bool operator<=(line& a, line& b);
	friend bool operator>=(line& a, line& b);
	friend bool operator==(line& a, line& b);
	friend bool operator!=(line& a, line& b);
	friend std::ostream& operator<<(std::ostream& cout, line& p);
	void output();
	line* reflect(line a);
	Figure* invert(circle a)  override;
};

