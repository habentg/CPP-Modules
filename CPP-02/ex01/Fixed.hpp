/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:36:37 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/02 13:22:33 by hatesfam         ###   ########.fr       */
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
};

std::ostream&  operator<<(std::ostream& os, const Fixed& rhs); // copy assignment operator

#endif //FIXED_HPP