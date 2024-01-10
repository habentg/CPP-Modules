/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:00:35 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/09 22:50:45 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    this->_c_brain = new Brain();
    this->_c_brain->fillIdeas("Cat idea");
    std::cout << "{DEFAULT} Cat type Constructor called." << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
    this->_c_brain = new Brain();
    this->_c_brain->fillIdeas(this->getType() + " idea");
    std::cout  << "{"  << this->getType() << "}" << " Cat type Constructor called." << std::endl;
}

Cat::~Cat(void) {
    if (this->_c_brain)
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
            this->_c_brain = new Brain();
            *this->_c_brain =  *rhs._c_brain;
        }
    }
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Me0wwwwww." << std::endl;
}

std::string Cat::getIdea(int index) const {
    if (index < 0 or index > 99)
    {
        std::cout << "index out of bound!" << std::endl;
        return "";
    }
    return this->_c_brain->getAnIdea(index);
}