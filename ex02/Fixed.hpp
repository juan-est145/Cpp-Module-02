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
	bool operator>(const Fixed &element) const;
	bool operator<(const Fixed &element) const;
	bool operator>=(const Fixed &element) const;
	bool operator<=(const Fixed &element) const;
	bool operator==(const Fixed &element) const;
	bool operator!=(const Fixed &element) const;
	Fixed operator+(const Fixed &element) const;
	Fixed operator-(const Fixed &element) const;
	Fixed operator*(const Fixed &element) const;
	Fixed operator/(const Fixed &element) const;
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);
	static int &min(Fixed &first, Fixed &second);
	static const int &min(const Fixed &first, const Fixed &second);
	static int &max(Fixed &first, Fixed &second);
	static const int &max(const Fixed &first, const Fixed &second);
	~Fixed(void);
};
std::ostream &operator<<(std::ostream &out, const Fixed &element);
#endif
