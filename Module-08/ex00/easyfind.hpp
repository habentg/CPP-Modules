/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:00:32 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/21 14:18:39 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>

class NoMatchFound : public std::exception {
    public:
        const char* what() const throw();
};

template<typename T>
typename T::iterator    easyfind(T& coll, int toBeFound)
{
    typename T::iterator it;
    for (it = coll.begin(); it != coll.end(); ++it) {
        if (*it == toBeFound)
            return  it;
    }
   throw NoMatchFound();
}

template<typename T>
void    printer(T& coll) {
    for (typename T::iterator it = coll.begin(); it != coll.end(); ++it)
    {
        if (it != coll.begin())
            std::cout << ", ";
        std::cout << *it;
    }
}