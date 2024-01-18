/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:36:37 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/02 16:14:52 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int                 _fpn_value;
        const static int    frac_bits;
    public:
        Fixed(void); // default constructor
        Fixed(const int ivalue); // parameterized constructor
        Fixed(const float fvalue); // parameterized constructor
        Fixed(const Fixed& rhs); // copy constructor
        ~Fixed(void); // destructor
        Fixed&  operator=(const Fixed& rhs); // copy assignment operator
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float   toFloat( void ) const;
        int     toInt( void ) const;

        // overloading 6 comparison operators
        bool operator>(const Fixed& rhs) const;
        bool operator>=(const Fixed& rhs) const;
        bool operator<(const Fixed& rhs) const;
        bool operator<=(const Fixed& rhs) const;
        bool operator==(const Fixed& rhs) const;
        bool operator!=(const Fixed& rhs) const;
        // overloading 4 arithmetic operators
        Fixed operator+(const Fixed& rhs) const;
        Fixed operator-(const Fixed& rhs) const;
        Fixed operator*(const Fixed& rhs) const;
        Fixed operator/(const Fixed& rhs) const;
        // overloading 4 increment/decrement operators (post and pre).
        Fixed operator++(int); // post +
        Fixed& operator++(); // pre +
        Fixed operator--(int); // post -
        Fixed& operator--(); // pre -
        // min and max member functions
        static Fixed& max( Fixed& lhs,  Fixed& rhs) ;
        static Fixed& min( Fixed& lhs,  Fixed& rhs) ;

        static const Fixed& max( const Fixed& lhs,  const Fixed& rhs) ;
        static const Fixed& min( const Fixed& lhs,  const Fixed& rhs) ;
};

std::ostream&  operator<<(std::ostream& os, const Fixed& rhs); // copy assignment operator

#endif //FIXED_HPP