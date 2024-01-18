/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:48:01 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/31 17:17:24 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// A static constant integer to store the number of fractional bits.
const int Fixed::frac_bits = 8;

// default constructor - setting the fixed point value to 0
Fixed::Fixed(void) : _fpn_value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// copy constructor, accepting a reference of Fixed object and performing a shallow copy, i.e. copying the value of the object.
// (*this).operator=(rhs); // calling the copy assignment operator
Fixed::Fixed(const Fixed& rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs; // calling the copy assignment operator, just a function call
    return ;
}

// copy assignment operator / =operator overload
Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fpn_value = rhs.getRawBits();
    return *this;
}

// destructor
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fpn_value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fpn_value = raw;
    return ;
}