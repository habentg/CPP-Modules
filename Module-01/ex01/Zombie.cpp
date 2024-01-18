/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:34:25 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/27 12:57:24 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
// default constructor
Zombie::Zombie(void)
{
    std::cout << "Zombie has been Created!!" << std::endl;
    return ;
}
// Parameterized constructor with member initializer list
// efficient way to initialize class members, considered best practice
Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << this->_name << " has been Created!!" << std::endl;
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << this->_name << " has been Destroyed!!" << std::endl;
    return ;
}

void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

