/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 02:34:52 by hatesfam          #+#    #+#             */
/*   Updated: 2024/03/23 10:42:14 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <exception>
# include <vector>
# include <list>
# include <climits>

class PmergeMe {
    private:
        PmergeMe();  
        PmergeMe(const PmergeMe& rhs);  
        PmergeMe& operator=(const PmergeMe& rhs);
    public:
        std::vector<unsigned long> vect;
        std::list<unsigned long> lst;
        double  vecSortingTime;
        double  lstSortingTime;
        ~PmergeMe();  
        PmergeMe(int ac, char **av);  

        void sortVector(std::vector<unsigned long>& vect);
        void sortList(std::list<unsigned long>& lst);

        class NotEnoughParams : public std::exception {
            public:
                const char* what() const throw();
        };
        class InvalidInput : public std::exception {
            public:
                const char* what() const throw();
        };
};

void    printVector(std::vector<unsigned long>& vec);
void    printList(std::list<unsigned long>& lst);
std::vector<unsigned long> split(std::string str, char delimiter);
std::string trim(std::string str);
#endif // !PMERGEME_HPP