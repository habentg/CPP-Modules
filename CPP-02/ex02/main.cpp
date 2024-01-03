/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:36:17 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/02 16:36:40 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    a = Fixed( 12 );
    // ''<<'' operator to insert the fixed point value in the standard output
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    // overloading 6 comparison operators
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    // arithmetic operators
    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "a - b: " << (a - b) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "a / b: " << (a / b) << std::endl;
    // increment/decrement operators (post and pre).
    std::cout << "a++: " << (a++) << std::endl;
    std::cout << "++a: " << (++a) << std::endl;
    std::cout << "a--: " << (a--) << std::endl;
    std::cout << "--a: " << (--a) << std::endl;
    // std::cout << "b--: " << (b--) << std::endl; // cant do this because b is const
    // std::cout << "--b: " << (--b) << std::endl;
    // min and max member functions
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    return 0;
}
