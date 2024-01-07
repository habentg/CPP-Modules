/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:01:50 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 20:55:22 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    this->_d_brain = new Brain();
    std::cout << "{DEFAULT} Dog type Constructor called." << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
    this->_d_brain = new Brain();
    std::cout  << "{"  << this->getType() << "}" << " Dog type Constructor called." << std::endl;
}

Dog::~Dog(void) {
    delete this->_d_brain;
    std::cout  << "{"  << this->getType() << "}" << " Dog Destructor called." << std::endl;
}

Dog::Dog(const Dog& cpy) : Animal("Dog") {
    *this = cpy;
    std::cout  << "{"  << this->getType() << "}" << " Dog Copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
    std::cout  << "{"  << this->getType() << "}" << " Dog Copy Assignment Operator called." << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
        if (rhs._d_brain)
        {
            for (size_t i = 0; i < 100; i++)
            {
                this->_d_brain[i] = rhs._d_brain[i];
            }  
        }
    }
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Barkkkkkkkk." << std::endl;
}