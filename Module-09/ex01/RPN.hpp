/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:15:44 by hatesfam          #+#    #+#             */
/*   Updated: 2024/03/23 10:20:24 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <exception>
# include <stack>
# include <list>
# include <deque>

class RPN {
    private:
        std::stack<double>  _s;
        // char**              _arrValues;
        RPN(void);
        RPN(const RPN& cpy);
        RPN& operator=(const RPN& rhs);
    public:
        //OCF
        RPN(char **av);
        ~RPN(void);
        // methods
        std::stack<double> getStack(void) const;
        void    postFixing(char** av);
        std::deque<std::string>    parser(char** av);
        void    doOperation(std::string& opertr);
        // exceptions
        class NoOperandsGiven : public std::exception {
            public:
                const char* what() const throw();
        };
        class StackHasMoreThanOneValue : public std::exception {
            public:
                const char* what() const throw();
        };
        class InvalidValue : public std::exception {
            public:
                const char* what() const throw();
        };
        class NotEnoughValuesForOp : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream&   operator<<(std::ostream& os, const RPN& obj);
std::deque<std::string> split(std::string& str, char delimiter);
std::string trim(std::string& str) ;
#endif // !RPN_HPP