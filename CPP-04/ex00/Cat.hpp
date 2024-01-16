/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:58:19 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/15 16:56:02 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat(void);
        Cat(const Cat& cpy);
        Cat& operator=(const Cat& cpy);
        ~Cat(void);
        // overriding makeSound() from Animal
        void    makeSound(void) const;
};

#endif // !CAT_HPP