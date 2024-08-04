/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:31:39 by juestrel          #+#    #+#             */
/*   Updated: 2024/08/04 18:12:30 by juestrel         ###   ########.fr       */
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

Fixed& Fixed::operator=(const Fixed &toCopy)
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

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}