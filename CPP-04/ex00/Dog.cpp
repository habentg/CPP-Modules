/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:01:50 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 19:42:34 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    std::cout << "{DEFAULT} Dog Constructor called." << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
    std::cout << "{"  << this->getType() << "}" << " Dog type Constructor called." << std::endl;
}

Dog::~Dog(void) {
    std::cout  << "{"  << this->getType() << "}" << " Dog Destructor called." << std::endl;
}

Dog::Dog(const Dog& cpy) : Animal("Dog") {
    *this = cpy;
    std::cout  << "{"  << this->getType() << "}" << " Dog Copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
    std::cout  << "{"  << this->getType() << "}" << " Dog Copy Assignment Operator called." << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Barkkkkkkkk." << std::endl;
}