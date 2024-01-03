/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:36:37 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/02 16:45:24 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
//  // Ortodox canonical form
class Fixed
{
    private:
        int                 _fpn_value;
        const static int    frac_bits;
    public:
        Fixed(void);                            // default constructor
        Fixed(const Fixed& copy);               // copy constructor
        ~Fixed(void);                           // destructor
        Fixed&  operator=(const Fixed& rhs);    // copy assignment operator
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif //FIXED_HPP