/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:00:35 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/05 20:20:22 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("default-Cat") {
    this->_c_brain = new Brain();
    std::cout << "{DEFAULT} Cat type Constructor called." << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
    this->_c_brain = new Brain();
    std::cout  << "{"  << this->getType() << "}" << " Cat type Constructor called." << std::endl;
}

Cat::~Cat(void) {
    delete this->_c_brain;
    std::cout  << "{"  << this->getType() << "}" << " Cat Destructor called." << std::endl;
}

Cat::Cat(const Cat& cpy) {
    *this = cpy;
    std::cout  << "{"  << this->getType() << "}" << " Copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
    std::cout  << "{"  << this->getType() << "}" << " Copy Assignment Operator called." << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Meowwwww." << std::endl;
}