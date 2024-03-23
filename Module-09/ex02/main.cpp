/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 07:40:44 by hatesfam          #+#    #+#             */
/*   Updated: 2024/03/23 07:27:39 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<unsigned int> split(std::string str, char delimiter) {
    std::vector<unsigned int> arr;
    std::string elem;
    long long       value;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == delimiter) {
            std::istringstream(elem) >> value;
            if (value > UINT32_MAXVALUE)
                throw PmergeMe::InvalidInput();
            arr.push_back(value);
            elem = "";
        } else {
            elem += str[i];
        }
    }
    std::istringstream(elem) >> value;
    arr.push_back(value); // Add the last element
    return arr;
}


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
            << "with std::lst<unsigned int> : " << obj.vecSortingTime << " µs" << std::endl;
        std::cout << "Time to process a range of " << obj.lst.size() << " elements " 
            << "with std::lst<unsigned int> : " << obj.lstSortingTime << " µs" << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
