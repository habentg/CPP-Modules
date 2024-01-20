/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 04:00:41 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/19 16:25:01 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <exception>
#include <cstring>
#include <stdlib.h>
#include <iomanip>

typedef enum e_type {
    UNKNOWN,  // unknow datatype 
    CHAR,     // char datatype 
    INT,      // int datatype
    FLOAT,    // float datatype
    DOUBLE,   // double datatype
    PINFF,    // positive infinity FLOAT
    NINFF,    // Negative infinity FLOAT
    NANNF,     // Non-Displayable FLOAT
    PINF,     // positive infinity DOUBLE
    NINF,     // Negative infinity DOUBLE
    NANN,     // Non-Displayable DOUBLE
}   t_type;

class ScalarConverter {
    protected:
        char        _char;
        int         _int;
        float       _float;
        double      _double;
        t_type      _type;
        bool        _impossible;
    public:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& cpy);
        ScalarConverter operator=(const ScalarConverter& rhs);
        ~ScalarConverter();
        // static method
        std::string printer(char code) const;
        static void convert(const char* value);
        // getter
        t_type  getType(void) const ;
        bool    isImpossible(void) const ;
        // custom exception class
        class UnknownType : public std::exception {
            public:
                const char* what() const throw();
        };
        class isImpossibleToDisplay : public std::exception {
            public:
                const char* what() const throw();
        };
        // helper methods
        t_type  setInputType(const char* input);
        void    setNumberType(const char* input);
        int     isInputPsuedoLiteral(const char* input);
        void    castAndSet(t_type dt, const char* input);
        // printers
        std::string printChar(void) const;
        std::string printInt(void) const;
        std::string printFloat(void) const;
        std::string printDouble(void) const;
};

std::ostream &operator<<(std::ostream &os, const ScalarConverter &conv);
#endif // !SCALARCONVERTER_HPP
