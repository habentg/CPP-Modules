/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:58:29 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/23 21:09:52 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <stack>
#include <deque>
#include <vector>
#include <list>
#include <iostream>
#include <string>

template<typename T>
class   MutantStack : public std::stack<T>{
    public:
        MutantStack<T>(void) {
            std::cout << "MutantStack<T> Default constructor. \n";
        };
        MutantStack<T>(const MutantStack<T>& cpy) : std::stack<T>(cpy) {
            std::cout << "MutantStack<T> Copy constructor. \n";
        };
        MutantStack<T>& operator=(const MutantStack<T>& rhs) {
            std::cout << "MutantStack<T> Copy Assignment operator. \n";
            if (this == &rhs)
                return *this;
			this->std::stack<T>::operator=(rhs);
			return *this;
        };
        ~MutantStack(void) {
            std::cout << "MutantStack<T> Destructor. \n";
        };
        // typedefing the iterators methods
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    
        // member functions
        iterator begin(void) {
            return std::stack<T>::c.begin(); // "std::stack<T>::c" exposes the underlying container
        }
        iterator end(void) {
            return std::stack<T>::c.end();
        }
        const_iterator begin(void) const {
            return std::stack<T>::c.begin();
        }
        const_iterator end(void) const {
            return std::stack<T>::c.end();
        }
        
        reverse_iterator rbegin(void) {
            return std::stack<T>::c.rbegin();
        }
        reverse_iterator rend(void) {
            return std::stack<T>::c.rend();
        }
        const_reverse_iterator rbegin(void) const {
            return std::stack<T>::c.rbegin();
        }
        const_reverse_iterator rend(void) const {
            return std::stack<T>::c.rend();
        }         
};
