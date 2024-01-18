/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:46:44 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/04 18:34:46 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
    private:
        std::string		_name;
        unsigned int	_hit_p;
        unsigned int	_enrg_p;
        unsigned int	_att_damage_p;
        
        static const unsigned int     defaultHitP = 10;
		static const unsigned int     defaultEnergyP = 10;
		static const unsigned int     defaultAttackDamage = 0;

    public:
    //Ortodox Canonical Form
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& copy);
        virtual ~ClapTrap(void);
        ClapTrap&   operator=(const ClapTrap& rhs);
    // setter and getters
        std::string		getName(void) const;
        unsigned int    getAttDamagePoint(void) const;
        unsigned int    getHitPoint(void) const;
        unsigned int    getEnrgPoint(void) const;
        void            setName( std::string name);
        void            setAttDamagePoint( unsigned int att_d_p);
        void            setHitPoint( unsigned int hit_p);
        void            setEnrgPoint( unsigned int enrgy_p);
    // member functions
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

#endif // !CLAPTRAP_HPP