/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:58:19 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 19:54:56 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat(void);
        WrongCat(std::string type);
        WrongCat(const WrongCat& cpy);
        WrongCat& operator=(const WrongCat& cpy);
        ~WrongCat(void);
        // overriding makeSound() from Animal
        void    makeSound(void) const;
};

#endif // !WRONGCAT_HPP