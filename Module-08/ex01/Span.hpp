/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:35:35 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/23 21:05:14 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
#include <climits>

class Span {
    private:
        std::vector<int>    _v;
        unsigned int _max_size;
        Span(void);
    public:
    //canonical form
        Span(unsigned int size);
        Span(const Span& cpy);
        Span& operator=(const Span& rhs);
        ~Span(void);
    // member funcs
        const std::vector<int>& getVector(void) const;
        unsigned int    getMaxSize(void) const;
        void    addNumber(int value);
        unsigned int shortestSpan(void);
        unsigned int longestSpan(void);
        void    rangeFiller(std::vector<int>::iterator vbegin, std::vector<int>::iterator vend);
    // exception class
        class AlreadyFull : public std::exception {
            public:
                const char* what() const throw();
        };
        class NoNumberStored : public std::exception {
            public:
                const char* what() const throw();
        };
        class OnlyOneStored : public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif // !SPAN_HPP