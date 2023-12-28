/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:33:53 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/27 09:41:36 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);
        void    setName(std::string name) { this->_name = name; };
        void    announce(void);
};

Zombie* zombieHorde( int N, std::string name );
#endif