/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:31:39 by juestrel          #+#    #+#             */
/*   Updated: 2024/08/05 23:30:17 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionNum = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedNumber = 0;
}

Fixed::Fixed(const Fixed &toCopy) : _fixedNumber(toCopy._fixedNumber)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int initialValue)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedNumber = initialValue << Fixed::_fractionNum;
}

Fixed::Fixed(const float initialValue)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedNumber = roundf(initialValue * (1 << Fixed::_fractionNum));
}

Fixed &Fixed::operator=(const Fixed &toCopy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &toCopy)
		this->_fixedNumber = toCopy._fixedNumber;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
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

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &element)
{
	out << element.toFloat();
	return (out);
}