#include "line.h"
	line::line(double k, double b) : k(k), b(b) {}
	line::line() : k(0), b(0) {}
	bool operator<(line& a, line& b) {
		return  a.k < b.k;
	}
	bool operator>(line& a, line& b) {
		return b < a;
	}
	bool operator<=(line& a, line& b) {
		return  !(a > b);
	}
	bool operator>=(line& a, line& b) {
		return !(a < b);
	}
	bool operator==(line& a, line& b) {
		return a.k == b.k;
	}
	bool operator!=(line& a, line& b) {
		return !(a == b);
	}
	void line::output() {
		std::cout << k << "x";
		if (b < 0) cout << b;
		else std::cout << "+" << b;
	}
	std::ostream& operator<<(std::ostream& cout, line& p) {
		std::cout <<p.k << "x";
		if (p.b < 0)	std::cout << p.b;
		else std::cout << "+" << p.b;
		return std::cout;
	}
	line* line::reflect(line a) {
		double tg = abs((a.k - k) / (1 + a.k * k));
		double newk = (tg + a.k) / (1 - a.k * tg);
		point temp(*this, a);
		double newb = temp.getX() - temp.getY() * newk;
		return new line(newk, newb);
	}
	Figure* line::invert(circle a) {
		if (k * a.getCenter().getX() + b == a.getCenter().getY()) {			//If line go through the circle center return same line
			return new line(k, b);
		}
		else {								//Line invert into the circle
			line normal(-1 / k, (-1, k) * a.getCenter().getX() - a.getCenter().getY());
			point q(normal, *this);
			point new_q = *(point*)q.invert(a);
			point new_center((a.getCenter().getX() + new_q.getX()) / 2, (a.getCenter().getY() + new_q.getY()) / 2);
			double new_rad =sqrt( pow(new_center.getX() - new_q.getX(), 2) + pow(new_center.getY()- new_q.getY(), 2));
			return new circle(new_center, new_rad);
		}
	}
	double line::getK(){
		return k;
	}
	double line::getB(){
		return b;
	}
