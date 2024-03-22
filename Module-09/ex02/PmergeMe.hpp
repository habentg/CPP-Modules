/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 02:34:52 by hatesfam          #+#    #+#             */
/*   Updated: 2024/03/22 03:40:28 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <exception>
# include <vector>
# include <list>

class PmergeMe {
  public:
    PmergeMe();  
    ~PmergeMe();  
    PmergeMe(const PmergeMe& rhs);  
    PmergeMe& operator=(const PmergeMe& rhs);

    void MIsortVector(std::vector<unsigned int>& vect);
    void MIsortList(std::list<unsigned int>& lst);

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
#endif // !PMERGEME_HPP