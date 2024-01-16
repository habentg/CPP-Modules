/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:59:33 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/15 16:57:00 by hatesfam         ###   ########.fr       */
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
        Dog(const Dog& cpy);
        Dog& operator=(const Dog& cpy);
        ~Dog(void);
        // overriding makeSound() from Animal
        void    makeSound(void) const;
    
};

#endif // !DOG_HPP