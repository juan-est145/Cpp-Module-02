#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;

public:
	Point(void);
	Point(const float num1, const float num2);
	Point(const Point &toCopy);
	Point &operator=(const Point &toCopy);
	~Point(void);
	Fixed getX(void) const;
	Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
float sign(Point const point, Point const a, Point const b);

#endif