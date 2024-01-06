/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:58:19 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/05 20:18:51 by hatesfam         ###   ########.fr       */
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
        void    makeSound(void) const;
    
};

#endif // !CAT_HPP