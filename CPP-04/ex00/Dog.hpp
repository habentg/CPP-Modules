/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:59:33 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/05 17:04:49 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog(void);
        Dog(std::string type);
        Dog(const Dog& cpy);
        Dog& operator=(const Dog& cpy);
        ~Dog(void);
        void    makeSound(void) const;
    
};

#endif // !DOG_HPP