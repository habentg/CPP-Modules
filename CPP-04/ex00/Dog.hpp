/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:59:33 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 19:33:06 by hatesfam         ###   ########.fr       */
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
        // overriding makeSound() from Animal
        void    makeSound(void) const;
    
};

#endif // !DOG_HPP