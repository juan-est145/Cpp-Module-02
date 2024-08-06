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
};
#endif