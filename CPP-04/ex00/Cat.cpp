/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:00:35 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 19:42:56 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
    std::cout << "{DEFAULT} Cat type Constructor called." << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
    std::cout  << "{"  << this->getType() << "}" << " Cat type Constructor called." << std::endl;
}

Cat::~Cat(void) {
    std::cout  << "{"  << this->getType() << "}" << " Cat Destructor called." << std::endl;
}

Cat::Cat(const Cat& cpy) : Animal("Cat") {
    *this = cpy;
    std::cout  << "{"  << this->getType() << "}" << " Cat Copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
    std::cout  << "{"  << this->getType() << "}" << " Cat Copy Assignment Operator called." << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Meowwwww." << std::endl;
}