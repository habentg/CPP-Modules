/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:49:43 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/03 16:58:26 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class FragTrap : public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string   name);
        FragTrap(const FragTrap& cpy);
        FragTrap&   operator=(const FragTrap& rhs);
        ~FragTrap(void);
        void    highFivesGuys(void);
};

#endif // FRAGTRAP_HPP