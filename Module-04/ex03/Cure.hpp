/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:18:32 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/07 00:59:10 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
    private:
    public:
        Cure(void);
        Cure(const Cure& cpy);
        Cure&   operator=(const Cure& rhs);
        ~Cure(void);
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif // CURE_HPP