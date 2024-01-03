/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:49:43 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/03 16:58:50 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(std::string   name);
        ScavTrap(const ScavTrap& cpy);
        ScavTrap&   operator=(const ScavTrap& rhs);
        ~ScavTrap(void);
        void    attack(const std::string& target);
        void    guardGate();
};

#endif // SCAVTRAP_HPP