/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:11:12 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 00:59:02 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
    private:
    public:
        Ice(void);
        Ice(const Ice& cpy);
        Ice&   operator=(const Ice& rhs);
        ~Ice(void);
        AMateria* clone() const;
        void use(ICharacter& target);
};


#endif // ICE_HPP