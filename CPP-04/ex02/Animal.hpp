/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:20:55 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 20:13:12 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal(void);
        Animal(std::string type);
        Animal(const Animal& cpy);
        Animal& operator=(const Animal& cpy);
        virtual ~Animal(void);
        // member func
        virtual void makeSound(void) const = 0; // makes the class abtract
        std::string getType(void) const;
};

#endif // !ANIMAL_HPP