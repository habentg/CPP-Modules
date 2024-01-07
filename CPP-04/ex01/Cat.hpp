/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:58:19 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 21:12:20 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain* _c_brain;
    public:
        Cat(void);
        Cat(std::string type);
        Cat(const Cat& cpy);
        Cat& operator=(const Cat& cpy);
        ~Cat(void);
        // overriding makeSound() from Animal
        void    makeSound(void) const;
        std::string     getIdea() const;
        void            setIdea();
};

#endif // !CAT_HPP