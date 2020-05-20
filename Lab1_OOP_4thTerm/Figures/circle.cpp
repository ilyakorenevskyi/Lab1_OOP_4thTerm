#include "circle.h"
#include "line.h"
#include "cmath"
	circle::circle() : center(point(0.0, 0.0)), rad(0) {}
	circle::circle(point c, double r) : center(c), rad(r) {}
	circle* circle::reflect(line a) {
		return new circle(*center.reflect(a), rad);
	}
	bool operator<(circle & a, circle & b) {
		return  a.rad < b.rad;
	}
	bool operator>(circle & a, circle & b) {
		return b < a;
	}
	bool operator<=(circle & a, circle & b) {
		return  !(a > b);
	}
	bool operator>=(circle & a, circle & b) {
		return !(a < b);
	}
	bool operator==(circle & a, circle & b) {
		return a.rad == b.rad;
	}
	bool operator!=(circle & a, circle & b) {
		return !(a == b);
	}
	void circle::output() {
		cout << rad;
	}
	std::ostream& operator<< (ostream & cout, circle & c) {
		cout << " Center:" << c.center << endl;
		cout << " Radius: " << c.rad << endl;
		return cout;
	}
	std::istream& operator>>(istream & cin, circle & c) {
		cin >> c.center >> c.rad;
		return cin;
	}
	Figure* circle::invert(circle a) {
		return nullptr;
	}
	double circle::getRad(){
		return rad;
	}
	point circle::getCenter(){
		return center;
	}

