/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:48:01 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/02 16:33:16 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ########################################################################################
                            **    Constructors && Destructor **
   ########################################################################################*/
// A static constant integer to store the number of fractional bits.
const int Fixed::frac_bits = 8;

// default constructor - setting the fixed point value to 0
Fixed::Fixed(void) : _fpn_value(0)
{
    return ;
}
// Parameterized constructor - setting the fixed point value to the integer value
Fixed::Fixed(const int value) : _fpn_value(value << Fixed::frac_bits)
{
    return ;
}

// Parameterized constructor - setting the fixed point value to the float value
Fixed::Fixed(const float value) : _fpn_value(static_cast<int>(roundf(value * (1 << Fixed::frac_bits))))
{
    return ;
}

// copy constructor, accepting a reference of Fixed object and performing a shallow copy, i.e. copying the value of the object.
// (*this).operator=(rhs); // calling the copy assignment operator
Fixed::Fixed(const Fixed& rhs)
{
    *this = rhs; // calling the copy assignment operator, just a function call
    return ;
}

// destructor
Fixed::~Fixed(void)
{
    return ;
}

/* ########################################################################################
                            **    Setter / Getter methods  **
   ########################################################################################*/

int Fixed::getRawBits(void) const
{
    return (this->_fpn_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_fpn_value = raw;
    return ;

}

/* ########################################################################################
                    **    Copy Assignment Operator  **
   ########################################################################################*/
// copy assignment operator / =operator overload
Fixed& Fixed::operator=(const Fixed& rhs)
{
    if (this != &rhs) // to handle self-assignment
        this->_fpn_value = rhs.getRawBits();
    return *this;
}

/* ########################################################################################
                            **    Fixed value to Int/Float  **
   ########################################################################################*/

// just reverse the process of the float constructor, devide by 2^_fractionalBits
float Fixed::toFloat() const {
    return static_cast<float>(this->_fpn_value) / (1 << Fixed::frac_bits);
}

int Fixed::toInt() const {
    return (this->_fpn_value >> Fixed::frac_bits);
}

/* ########################################################################################
                            **    Comparison operators    **
   ########################################################################################*/
bool Fixed::operator>(const Fixed& rhs) const {
    return (this->_fpn_value > rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return (this->_fpn_value >= rhs.getRawBits());
}

bool Fixed::operator<(const Fixed& rhs) const {
    return (this->_fpn_value < rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return (this->_fpn_value <= rhs.getRawBits());
}
bool Fixed::operator!=(const Fixed& rhs) const {
    return (this->_fpn_value != rhs.getRawBits());
}

bool Fixed::operator==(const Fixed& rhs) const {
    return (this->_fpn_value == rhs.getRawBits());
}

/* ########################################################################################
                            **    Arthmetic operators    **
   ########################################################################################*/
Fixed Fixed::operator+(const Fixed& rhs) const {
    return (Fixed(this->toFloat() + rhs.toFloat()));
}
Fixed Fixed::operator-(const Fixed& rhs) const {
    return (Fixed(this->toFloat() - rhs.toFloat()));
}
Fixed Fixed::operator*(const Fixed& rhs) const {
    return (Fixed(this->toFloat() * rhs.toFloat()));
}
Fixed Fixed::operator/(const Fixed& rhs) const {
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

/* ########################################################################################
                            **    increment/decrement operators    **
   ########################################################################################*/
// postfix operators should provide the original value before the increment or decrement.
// prefix operators should provide the value after the increment or decrement.
Fixed& Fixed::operator++() {
    ++(_fpn_value);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed cpy_a = (*this);
    ++(*this);
    return cpy_a;
}

Fixed& Fixed::operator--() {
    --(_fpn_value);
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed cpy_a = (*this);
    --(*this);
    return cpy_a;
}

/* ########################################################################################
                            **    min/max member functions    **
   ########################################################################################*/
Fixed& Fixed::max( Fixed& lhs, Fixed& rhs) {
    return (lhs > rhs ? lhs : rhs);
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs) {
    return (lhs < rhs ? lhs : rhs);
}

const Fixed& Fixed::max( const Fixed& lhs, const Fixed& rhs) {
    return (lhs > rhs ? lhs : rhs);
}

const Fixed& Fixed::min( const Fixed& lhs, const Fixed& rhs) {
    return (lhs < rhs ? lhs : rhs);
}

/* ########################################################################################
                            **  non-member functions    **
   ########################################################################################*/
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