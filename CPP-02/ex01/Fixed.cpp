/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:48:01 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/02 13:43:28 by hatesfam         ###   ########.fr       */
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
// Parameterized constructor - setting the fixed point value to the integer value
Fixed::Fixed(const int value) : _fpn_value(value << Fixed::frac_bits)
{
    std::cout << "Int constructor called" << std::endl;
    return ;
}

// Parameterized constructor - setting the fixed point value to the float value
Fixed::Fixed(const float value) : _fpn_value(static_cast<int>(roundf(value * (1 << Fixed::frac_bits))))
{
    std::cout << "Float constructor called" << std::endl;
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
    if (this != &rhs) // to handle self-assignment
        this->_fpn_value = rhs.getRawBits();
    return *this;
}

// <<operator overload
    // the << operator is a binary operator, which means it takes two arguments.
    // the first argument is the ostream object, and the second argument is the object to be printed.
    // the return type of the << operator is the ostream object itself, so that we can chain multiple << operators together.
    // basically, we overload the << operator to print the value of the Fixed object, since the default << operator doesn't know how to print the value of a Fixed object.
// NOTE: we can't overload the << operator as a member function, because the left operand is not a Fixed object.
std::ostream& operator<<(std::ostream& os, const Fixed& rhs)
{
    os << rhs.toFloat();
    return os;
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
// just reverse the process of the float constructor, devide by 2^_fractionalBits
float Fixed::toFloat() const {
    return static_cast<float>(_fpn_value) / (1 << Fixed::frac_bits);
}

int Fixed::toInt() const {
    return (this->_fpn_value >> Fixed::frac_bits);
}
