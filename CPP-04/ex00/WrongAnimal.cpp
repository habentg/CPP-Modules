/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:52:20 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 19:53:00 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("W_DEFAULT") {
    std::cout << "[W_DEFAULT] WrongAnimal type Constructor called." << std::endl;
}
WrongAnimal::WrongAnimal(std::string type) : type(type) {
    std::cout << "[" <<  this->type << "]"  << " WrongAnimal type Constructor called." << std::endl;
}
WrongAnimal::~WrongAnimal(void) {
    std::cout << "[" <<  this->type << "]" << " WrongAnimal Destructor called." << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& cpy) {
    *this = cpy;
    std::cout << "[" <<  this->type << "]" << " Copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
    std::cout << "[" <<  this->type << "]" << " Copy Assignment Operator called." << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "[DEFAULT] WrongAnimal sound." << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return this->type;
}
