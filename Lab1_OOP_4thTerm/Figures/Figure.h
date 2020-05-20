#pragma once
class line;
class circle;
class Figure {
public:
	virtual Figure* reflect(line a) =0 ;
	virtual Figure* invert(circle a) = 0;
};