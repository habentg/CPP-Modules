/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 07:40:44 by hatesfam          #+#    #+#             */
/*   Updated: 2024/03/23 10:38:43 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av) {
    try {
        if (ac < 2)
            PmergeMe::NotEnoughParams();
        for (int i = 1; i < ac; i++) {
            if (std::string(av[i]).find_first_not_of("0123456789 ") != std::string::npos)
                PmergeMe::InvalidInput();
        }
        PmergeMe obj(ac, av);
        std::cout << "Before sort ";
        // printList(obj.lst);
        printVector(obj.vect);
        obj.sortVector(obj.vect);
        obj.sortList(obj.lst);
        std::cout << "After after ";
        // printList(obj.lst);
        printVector(obj.vect);
        std::cout << "Time to process a range of " << obj.vect.size() << " elements " 
            << "with std::vector<unsigned long> : " << obj.vecSortingTime << " µs" << std::endl;
        std::cout << "Time to process a range of " << obj.lst.size() << " elements " 
            << "with std::list<unsigned long> : " << obj.lstSortingTime << " µs" << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
