/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:31:39 by juestrel          #+#    #+#             */
/*   Updated: 2024/08/06 13:48:42 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionNum = 8;

Fixed::Fixed()
{
	this->_fixedNumber = 0;
}

Fixed::Fixed(const Fixed &toCopy) : _fixedNumber(toCopy._fixedNumber) {}

Fixed::Fixed(const int initialValue)
{
	this->_fixedNumber = initialValue << Fixed::_fractionNum;
}

Fixed::Fixed(const float initialValue)
{
	this->_fixedNumber = roundf(initialValue * (1 << Fixed::_fractionNum));
}

Fixed &Fixed::operator=(const Fixed &toCopy)
{
	if (this != &toCopy)
		this->_fixedNumber = toCopy._fixedNumber;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_fixedNumber);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedNumber = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedNumber / (1 << Fixed::_fractionNum));
}

int Fixed::toInt(void) const
{
	return (this->_fixedNumber >> Fixed::_fractionNum);
}

bool Fixed::operator>(const Fixed &element) const
{
	return (this->_fixedNumber > element._fixedNumber);
}

bool Fixed::operator<(const Fixed &element) const
{
	return (this->_fixedNumber < element._fixedNumber);
}

bool Fixed::operator>=(const Fixed &element) const
{
	return (this->_fixedNumber >= element._fixedNumber);
}

bool Fixed::operator<=(const Fixed &element) const
{
	return (this->_fixedNumber <= element._fixedNumber);
}

bool Fixed::operator==(const Fixed &element) const
{
	return (this->_fixedNumber == element._fixedNumber);
}

bool Fixed::operator!=(const Fixed &element) const
{
	return (this->_fixedNumber != element._fixedNumber);
}

Fixed Fixed::operator+(const Fixed &element) const
{
	return (Fixed(this->toFloat() + element.toFloat()));
}

Fixed Fixed::operator-(const Fixed &element) const
{
	return (Fixed(this->toFloat() - element.toFloat()));
}

Fixed Fixed::operator*(const Fixed &element) const
{
	return (Fixed(this->toFloat() * element.toFloat()));
}

Fixed Fixed::operator/(const Fixed &element) const
{
	return (Fixed(this->toFloat() / element.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->_fixedNumber++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->_fixedNumber--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	return (first < second ? first : second);
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	return (first < second ? first : second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	return (first > second ? first : second);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	return (first > second ? first : second);
}

Fixed::~Fixed(void) {}

std::ostream &operator<<(std::ostream &out, const Fixed &element)
{
	out << element.toFloat();
	return (out);
}