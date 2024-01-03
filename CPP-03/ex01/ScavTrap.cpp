/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:49:33 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/03 20:47:45 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


/* ########################################################################################
                            **    Orthodox Canonical Form  **
   ########################################################################################*/

ScavTrap::ScavTrap(void) : ClapTrap()
{
    std::cout << "ScavTrap Constructor: Default" << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->setAttDamagePoint(20);
    this->setHitPoint(100);
    this->setEnrgPoint(50);
    std::cout << "ScavTrap Constructor: ScavTrap " << this->getName() << " Created!" << std::endl;
}
ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Destructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& cpy) : ClapTrap()
{
    *this = cpy;
    std::cout << " ScavTrap Copy Constructor called." << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& rhs)
{
    std::cout << "ScavTrap Copy Assignment Operator called." << std::endl;
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

void    ScavTrap::attack(const std::string& target) {
    if (this->getEnrgPoint() <= 0 || this->getHitPoint() <= 0) {
        if (this->getHitPoint() <= 0)
            std::cout << "ScavTrap " << this->getName() << " cant Attack, He is DEAD!" << std::endl;
        else
            std::cout << "ScavTrap " << this->getName() << " cant Attack, He is out of ENERGY!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttDamagePoint() << " points of damage!" << std::endl;
        this->setEnrgPoint(this->getEnrgPoint() - 1);;
        if (this->getEnrgPoint() <= 0)
            std::cout << "Warning: ScavTrap " << this->getName() << " Exhousted its ENERGY!" << std::endl;
    }
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getName() << " has entered in Gate keeper mode." << std::endl;
}