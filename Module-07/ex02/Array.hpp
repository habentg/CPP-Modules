/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:49:40 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/19 14:46:04 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

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
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& rhs);
#endif // !ARRAY_HPP