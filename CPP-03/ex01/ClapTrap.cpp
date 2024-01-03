/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:49:33 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/03 18:33:56 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


/* ########################################################################################
                            **    Orthodox Canonical Form  **
   ########################################################################################*/

ClapTrap::ClapTrap(void)
{
    std::cout << "ClapTrap Constructor: Default" << std::endl;
}
ClapTrap::ClapTrap(std::string name)
    : _name(name), _hit_p(10), _enrg_p(10), _att_damage_p(0)
{
    std::cout << "ClapTrap Constructor: ClapTrap " << this->getName() << " Created!" << std::endl;
}
ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Destructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& cpy)
{
    *this = cpy;
    std::cout << " ClapTrap Copy Constructor called." << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& rhs)
{
    std::cout << "ClapTrap Copy Assignment Operator called." << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs.getName() ;
        this->_att_damage_p = rhs.getAttDamagePoint();
        this->_hit_p = rhs.getHitPoint();
        this->_enrg_p = rhs.getEnrgPoint();
    }
    return *this;
}

/* ########################################################################################
                            **    Getter funcitons  **
   ########################################################################################*/
std::string		ClapTrap::getName(void) const { return this->_name;}
unsigned int    ClapTrap::getAttDamagePoint(void) const { return this->_att_damage_p;}
unsigned int    ClapTrap::getHitPoint(void) const { return this->_hit_p; }
unsigned int    ClapTrap::getEnrgPoint(void) const { return this->_enrg_p; }

void            ClapTrap::setName( std::string name) { this->_name = name; }
void            ClapTrap::setAttDamagePoint( unsigned int att_d_p) { this->_att_damage_p = att_d_p; }
void            ClapTrap::setHitPoint( unsigned int hit_p) { this->_hit_p = hit_p; }
void            ClapTrap::setEnrgPoint( unsigned int enrgy_p) { this->_enrg_p = enrgy_p; }

/* ########################################################################################
                            **    Member funcitons  **
   ########################################################################################*/
void    ClapTrap::attack(const std::string& target) {
    if (this->_enrg_p <= 0)
        std::cout << "ClapTrap " << this->getName() << " is out of energy!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttDamagePoint() << " points of damage!" << std::endl;
        this->_enrg_p -=  1;
    }
}

void   ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hit_p <= 0)
        std::cout << "ClapTrap " << this->getName() << " is already dead!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage!" << std::endl;
        this->_hit_p -= amount;
    }
}

void    ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "ClapTrap " << this->getName() << " is being repaired for " << amount << " points!" << std::endl;
    this->_hit_p += amount;
    this->_enrg_p -=  1;
}
