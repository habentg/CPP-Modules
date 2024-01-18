/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:34:25 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/29 17:53:17 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// constructor with member initializer list
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

// creating a new Zombie on the heap using the new keyword
Zombie* newZombie( std::string name )
{
    Zombie *nz = new Zombie(name);
    return (nz);
}

// creating a new Zombie on the heap and calling announce on it and then deleting it
void randomChump( std::string name )
{
    Zombie *rc = new Zombie(name);
    rc->announce();
    delete rc;
}
