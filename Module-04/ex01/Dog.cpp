/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:01:50 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/09 22:49:51 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
    this->_d_brain = new Brain();
    this->_d_brain->fillIdeas("dog idea");
    std::cout << "{DEFAULT} Dog type Constructor called." << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
    this->_d_brain = new Brain();
    this->_d_brain->fillIdeas(this->getType() + " idea");
    std::cout  << "{"  << this->getType() << "}" << " Dog type Constructor called." << std::endl;
}

Dog::~Dog(void) {
    if (this->_d_brain)
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
            this->_d_brain = new Brain();
            *this->_d_brain =  *rhs._d_brain;
        }
    }
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Barkkkkkkkk." << std::endl;
}

std::string Dog::getIdea(int index) const {
    if (index < 0 or index > 99)
    {
        std::cout << "index out of bound!" << std::endl;
        return "";
    }
    return this->_d_brain->getAnIdea(index);
}