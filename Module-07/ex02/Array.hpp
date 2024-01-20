/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:49:40 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/19 20:39:23 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

template<typename T>
class Array {
    private:
        T*              _my_arr;
        unsigned int    _arr_size;
    public:
        Array(void);
        Array(unsigned int size);
        Array(const Array& cpy);
        ~Array(void);
        Array&   operator=(const Array& rhs);
        //member func
        size_t  size() const;
        // exception clas
        class IndexOuttaRange : public std::exception {
            public:
                const char* what() const throw() {
                    return "Index outta Range!";
                };
        };
        // '[]' overloader
        T& operator[]( unsigned int i ) const {
            if ( i >= this->_arr_size)
                throw IndexOuttaRange();
            return this->_my_arr[i];
        }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& rhs);

#include "Array.tpp"
#endif // !ARRAY_HPP