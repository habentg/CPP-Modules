/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:00:32 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/25 16:52:04 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

class NoMatchFound : public std::exception {
    public:
        const char* what() const throw();
};

template<typename T>
void   easyfind(T& coll, int toBeFound)
{
    typename T::iterator it = std::find(coll.begin(), coll.end(), toBeFound);
    if (it == coll.end())
        throw NoMatchFound();
    std::cout << "Value: " << toBeFound << " found at index: " << std::distance(coll.begin(), it);
}
/*

typename T::iterator it;
    -> typename just tells the compiler that 'T::iterator' is a type i.e we dont have a class thats called "T" that has static variable "iterator".
std::find() -> member of algorithm library
    -> Returns an iterator to the first element in the range [first, last) that satisfies specific criteria.
    -> it will return the iterator to the end of the collection if no match is found.
*/
template<typename T>
void    printer(T& coll) {
    for (typename T::iterator it = coll.begin(); it != coll.end(); ++it)
    {
        if (it != coll.begin())
            std::cout << ", ";
        std::cout << *it;
    }
}