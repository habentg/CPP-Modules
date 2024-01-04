/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:33:42 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/04 16:36:45 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) { std::cout << "Animal Default Constructor called."}
Animal::~Animal(void) { std::cout << "Animal Destructor called."}
Animal::Animal(const Animal& cpy) {
    *this = cpy;
    std::cout << "Animal Destructor called."
}

Animal& operator(const Animal& rhs) {
    if (this != &rhs)
        *this = 
}