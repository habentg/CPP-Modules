/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:58:29 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/21 20:05:03 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <algorithm>
#include <stack>
#include <iostream>
#include <string>

template<typename T>
class   MutantStack {
    private:
        std::stack<T>   st;
    public:
        MutantStack(void);
        MutantStack(const MutantStack& cpy);
        MutantStack& operator=(const MutantStack& rhs);
        ~MutantStack(void);
        // member methods
        
        // overloaders
         
};

#endif // !MUTANTSTACK_HPP