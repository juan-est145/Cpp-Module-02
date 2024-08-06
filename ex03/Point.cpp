/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:53:03 by juestrel          #+#    #+#             */
/*   Updated: 2024/08/06 13:46:11 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const float num1, const float num2) : _x(num1), _y(num2) {}

Point::Point(const Point &toCopy) : _x(toCopy._x), _y(toCopy._y) {}

Point &Point::operator=(const Point &toCopy)
{
	(void)toCopy;
	std::cout << "Cannot assign values to const members _x and _y" << std::endl;
	return (*this);
}

Point::~Point(void) {}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}