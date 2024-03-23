/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 02:34:52 by hatesfam          #+#    #+#             */
/*   Updated: 2024/03/23 07:28:39 by hatesfam         ###   ########.fr       */
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
# define UINT32_MAXVALUE 4294967295
class PmergeMe {
    private:
        PmergeMe();  
        PmergeMe(const PmergeMe& rhs);  
        PmergeMe& operator=(const PmergeMe& rhs);
    public:
        std::vector<unsigned int> vect;
        std::list<unsigned int> lst;
        double  vecSortingTime;
        double  lstSortingTime;
        ~PmergeMe();  
        PmergeMe(int ac, char **av);  

        void sortVector(std::vector<unsigned int>& vect);
        void sortList(std::list<unsigned int>& lst);

        class NotEnoughParams : public std::exception {
            public:
                const char* what() const throw();
        };
        class InvalidInput : public std::exception {
            public:
                const char* what() const throw();
        };
};

void    printVector(std::vector<unsigned int>& vec);
void    printList(std::list<unsigned int>& lst);
std::vector<unsigned int> split(std::string str, char delimiter);
#endif // !PMERGEME_HPP