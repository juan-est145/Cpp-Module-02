#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _fixedNumber;
	const static int _fractionNum;

public:
	Fixed(void);
	Fixed(const Fixed &toCopy);
	Fixed &operator=(const Fixed &toCopy);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	~Fixed(void);
};
#endif
