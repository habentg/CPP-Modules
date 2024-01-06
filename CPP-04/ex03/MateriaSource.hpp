/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:39:01 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/06 19:41:01 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

/*
    MateriaSource has the ability to:
        * Copies the Materia passed as a parameter and store it in memory so it can be cloned later.
*/
class MateriaSource : public IMateriaSource {
    protected:
        AMateria* _m_arr[4];
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource& cpy);
        MateriaSource&   operator=(const MateriaSource& rhs);
        ~MateriaSource();
        // member functions
        void        learnMateria(AMateria* toBeLearned);
        AMateria*   createMateria(std::string const & type);
};

#endif //!MATERIASOURCE_HPP