/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:38:37 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/06 19:40:54 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// default constructor
MateriaSource::MateriaSource(void) {
    for (size_t i = 0; i < 4; i++)
    {
        this->_m_arr[i] = NULL;
    }
    std::cout << "# MateriaSource Constructor Called #" << std::endl;
}
// destructor
MateriaSource::~MateriaSource(void) {
    for (size_t i = 0; i < 4; i++)
    {
        if (this->_m_arr[i])
        {
            delete this->_m_arr[i];
            this->_m_arr[i] = NULL;
        }
    }
    std::cout << "# MateriaSource Destructor Called #" << std::endl;
}
// copy constructor
MateriaSource::MateriaSource(const MateriaSource& cpy) {
    std::cout << "# MateriaSource Copy Constructor Called #" << std::endl;
    *this = cpy;
}
// copy assignment operator
MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
    if (this != &rhs)
    {
        for (size_t i = 0; i < 4; i++)
        {
            if (this->_m_arr[i])
            {
                delete this->_m_arr[i];
                this->_m_arr[i] = NULL;
            }
        }
        for (size_t i = 0; i < 4; i++)
            this->_m_arr[i] = rhs._m_arr[i];
    }
    return *this;
}

// ----------------------- MEMBER FUNCTIONS ------------------
void    MateriaSource::learnMateria(AMateria* toBeLearned) {
    for (size_t i = 0; i < 4; i++) {
        if (this->_m_arr[i] == NULL) {
            this->_m_arr[i] = toBeLearned;
            std::cout << "# MateriaSource learned " << toBeLearned->getType() << " #" << std::endl;
            return ;
        }
            std::cout << "# MateriaSource can't learn " << toBeLearned->getType() << " #" << std::endl;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
     for ( int i = 0; i < 4; i++ ) {
        if ( _m_arr[i] && _m_arr[i]->getType() == type )
            return _m_arr[i]->clone();
     }
    return NULL;
}