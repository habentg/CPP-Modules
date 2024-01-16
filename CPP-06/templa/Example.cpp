/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Example.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:40:43 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/14 06:05:25 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// example.cpp

#ifndef EXAMPLE_CPP
#define EXAMPLE_CPP

#include "Example.hpp"

template <typename T>
Example<T>::Example(T value) : data(value) {}
template <typename T>
Example::~Example(void) {}

template <typename T>
T Example<T>::getValue() const {
    return data;
}

// Explicit instantiation for the types you anticipate using
template class Example<int>;  // For int
template class Example<char>;  // For char
template class Example<double>;  // For double
template class Example<float>;  // For float

#endif  // EXAMPLE_CPP
