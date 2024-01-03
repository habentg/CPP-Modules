/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:19:04 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/03 19:30:36 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


/* ########################################################################################
                            **    Orthodox Canonical Form  **
   ########################################################################################*/

FragTrap::FragTrap(void) : ClapTrap()
{
    std::cout << "FragTrap Constructor: Default" << std::endl;
}
FragTrap::FragTrap(std::string name)
    : ClapTrap(name)
{
    this->setAttDamagePoint(30);
    this->setHitPoint(100);
    this->setEnrgPoint(100);
    std::cout << "FragTrap Constructor: FragTrap " << this->getName() << " Created!" << std::endl;
}
FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& cpy) : ClapTrap()
{
    *this = cpy;
    std::cout << " FragTrap Copy Constructor called." << std::endl;
}

FragTrap&   FragTrap::operator=(const FragTrap& rhs)
{
    std::cout << "FragTrap Copy Assignment Operator called." << std::endl;
    if (this != &rhs)
    {
        this->setName( rhs.getName() );
        this->setAttDamagePoint(rhs.getAttDamagePoint());
        this->setHitPoint(rhs.getHitPoint());
        this->setAttDamagePoint(rhs.getEnrgPoint());
    }
    return *this;
}

/* ########################################################################################
                            **    Member funcitons  **
   ########################################################################################*/

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->getName() << " says: High five, guys!" << std::endl;
}
