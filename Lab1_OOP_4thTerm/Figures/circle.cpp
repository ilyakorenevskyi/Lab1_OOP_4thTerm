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
		if (a.checkPoint(center)) {
			point circle_point1(a.getCenter().getX() + rad, a.getCenter().getY());
			point circle_point2(a.getCenter().getX() - rad, a.getCenter().getY());
			if (circle_point1 == center) {
				circle_point1 = point(a.getCenter().getX(), a.getCenter().getY()+a.getRad());
			}
			if (circle_point2 == center) {
				circle_point2 = point(a.getCenter().getX(), a.getCenter().getY()+ a.getRad());
			}
			return new line(circle_point1, circle_point2);
		}
		else {
			double s = pow(rad, 2) / (pow(a.getCenter().getX() - center.getX(), 2) + pow(a.getCenter().getY() - center.getY(), 2) - pow(a.getRad(), 2));
			double new_x = center.getX() + s * (a.getCenter().getX() - center.getX());
			double new_y = center.getY() + s * (a.getCenter().getY() - center.getY());
			double new_r = a.getRad() * abs(s);
			return new circle({ new_x,new_y }, new_r);
		}
	}
	bool circle::checkPoint(point to_check) {
		return rad == pow(to_check.getX() - center.getX(),2) + pow(to_check.getY() - center.getY(), 2);
	}
	double circle::getRad(){
		return rad;
	}
	point circle::getCenter(){
		return center;
	}

