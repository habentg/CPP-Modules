/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:58:15 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/23 21:13:02 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << "========== MutantStack ==========" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
	std::cout << "\nITERATING ON MutantStack:" << std::endl;
    while (it != ite)
    {
        if (it != mstack.begin())
            std::cout << ", ";
        std::cout << *it;
        ++it;
    }
    std::cout << std::endl;
    std::stack<int> s(mstack);

    std::cout << "========== LIST ==========" << std::endl;
	
	std::list<int> ls;
	ls.push_back(5);
	ls.push_back(17);
	std::cout << "Back: " << ls.back() << std::endl; // top for stack
	ls.pop_back();
	std::cout << "Size: " << ls.size() << std::endl;
	ls.push_back(3);
	ls.push_back(7);
	ls.push_back(737);
	ls.push_back(0);
	std::cout << "Size: " << ls.size() << std::endl;
	std::list<int>::iterator lit = ls.begin();
	std::list<int>::iterator lite = ls.end();
	++lit;
	--lit;
	std::cout << "\nITERATING ON LIST:" << std::endl;
	while (lit != lite) {
        if (lit != ls.begin())
            std::cout << ", ";
        std::cout << *lit;
        ++lit;
	}
    std::cout << std::endl;
    return 0;
}