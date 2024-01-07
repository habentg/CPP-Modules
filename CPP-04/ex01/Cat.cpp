/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:00:35 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 20:54:15 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
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

Cat::Cat(const Cat& cpy) : Animal("Cat") {
    *this = cpy;
    std::cout  << "{"  << this->getType() << "}" << " Cat Copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
    std::cout  << "{"  << this->getType() << "}" << " Cat Copy Assignment Operator called." << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
        if (rhs._c_brain)
        {
            for (size_t i = 0; i < 100; i++)
            {
                this->_c_brain[i] = rhs._c_brain[i];
            }  
        }
    }
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Meowwwww." << std::endl;
}
