#include "point.h"
#include "line.h"
	point::point() : x(), y() {}
	point:: point(double x, double y) : x(x), y(y) {}
	point::point(line l1, line l2) {
		x = (l1.getB() - l2.getB()) / (l2.getK() - l1.getK());
		y = x * l1.getK() + l1.getB();
	}
	double point::getX()
	{
		return x;
	}
	double point::getY()
	{
		return y;
	}
	point* point::invert(circle a) {
		return new point(a.getCenter().x + pow(a.getRad(), 2) * (x - a.getCenter().x) / (pow((x - a.getCenter().x), 2) + pow((y - a.getCenter().y), 2)), a.getCenter().y + pow(a.getRad(), 2) * (y - a.getCenter().y) / (pow((x - a.getCenter().x), 2) + pow((y - a.getCenter().y), 2)));
	}
	point* point::reflect(line a) {    // Finding point reflection 
		line normal(-1 / a.getK(), y - (-1 / a.getK()) * x); // Normal line to our line
		point temp(normal, a);						// cross point
		return new point((2 * temp.x - x), (2 * temp.y - y));
	}
	std::ostream& operator<<(std::ostream& cout, point& p) {
		cout << "(" << p.x << "," << p.y << ")";
		return cout;
	}
	void point::output() {
		cout << x << " " << y;
	}
	bool operator<(point& a, point& b) {
		return  pow(a.x, 2) + pow(a.y, 2) < pow(b.x, 2) + pow(b.y, 2);
	}
	bool operator>(point& a, point& b) {
		return b < a;
	}
	bool operator<=(point& a, point& b) {
		return  !(a > b);
	}
	bool operator>=(point& a, point& b) {
		return !(a < b);
	}
	bool operator==(point& a, point& b) {
		return pow(a.x, 2) + pow(a.y, 2) == pow(b.x, 2) + pow(b.y, 2);
	}
	bool operator!=(point& a, point& b) {
		return !(a == b);
	}
	std::istream& operator>>(std::istream & cin, point & p) {
		std::cin >> p.x >> p.y;
		return cin;
	}
