/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:55:27 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 20:01:27 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
    std::cout << "{DEFAULT} WrongCat type Constructor called." << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
    std::cout  << "{"  << this->getType() << "}" << " WrongCat type Constructor called." << std::endl;
}

WrongCat::~WrongCat(void) {
    std::cout  << "{"  << this->getType() << "}" << " WrongCat Destructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& cpy) : WrongAnimal("WrongCat") {
    *this = cpy;
    std::cout  << "{"  << this->getType() << "}" << " WrongCat Copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
    std::cout  << "{"  << this->getType() << "}" << " WrongCat Copy Assignment Operator called." << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

void WrongCat::makeSound(void) const {
    std::cout << "Meowwwww." << std::endl;
}