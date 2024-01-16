/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:33:42 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/15 16:53:09 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("DEFAULT") {
    std::cout << "[DEFAULT] Animal type Constructor called." << std::endl;
}
Animal::Animal(std::string type) : type(type) {
    std::cout << "[" <<  this->type << "]"  << " Animal type Constructor called." << std::endl;
}
Animal::~Animal(void) {
    std::cout << "[" <<  this->type << "]" << " Animal Destructor called." << std::endl;
}
Animal::Animal(const Animal& cpy) {
    std::cout << "[" <<  this->type << "]" << " Copy constructor called." << std::endl;
    *this = cpy;
}

Animal& Animal::operator=(const Animal& rhs) {
    std::cout << "[" <<  this->type << "]" << " Copy Assignment Operator called." << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

void Animal::makeSound(void) const {
    std::cout << "[DEFAULT] Animal sound." << std::endl;
}

std::string Animal::getType(void) const {
    return this->type;
}
