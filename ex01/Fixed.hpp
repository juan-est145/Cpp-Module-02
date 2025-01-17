#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _fixedNumber;
	const static int _fractionNum;

public:
	Fixed(void);
	Fixed(const Fixed &toCopy);
	Fixed(const int initialValue);
	Fixed(const float initialValue);
	Fixed &operator=(const Fixed &toCopy);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	~Fixed(void);
};
std::ostream &operator<<(std::ostream &out, const Fixed &element);
#endif
