/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:14:15 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/05 20:24:04 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain type Constructor called." << std::endl;
}

Brain::~Brain(void) {
    std::cout << "Brain Destructor called." << std::endl;
}

Brain::Brain(const Brain& cpy) {
    *this = cpy;
    std::cout << "Brain Copy constructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
    std::cout << "Brain Copy Assignment Operator called." << std::endl;
    if (this != &rhs) {
        for (size_t i = 0; i < 100; i++)
        {
            this->_ideas[i] = rhs._ideas[i];
        } 
    }
    return *this;
}
