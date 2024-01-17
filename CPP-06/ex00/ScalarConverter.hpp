/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 04:00:41 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/17 06:14:55 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <limits>
#include <exception>

// my macros
// # define INT_MAX 2147483647
// # define INT_MIN -2147483648


// typedef enum e_id {
//     FINE,
//     NON_DESPLAYABLE,
//     NANF,
//     NAND,
//     IMPOSSIBLE
// } t_id;

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
        t_type  _type;
        std::string _input;
        bool        _impossible;
        // t_id    _id[4];
    public:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& cpy);
        ScalarConverter operator=(const ScalarConverter& rhs);
        ~ScalarConverter();
        // static method
        std::string printer(char code) const;
        static void convert(std::string& value);
        // getter
        t_type getType(void) const ;
        // custom exception class
        class UnknownType : public std::exception {
            public:
                const char* whatCustom() const throw();
        };
        // helper methods
        t_type  setInputType(std::string& input);
        int     setNumberType(std::string& input);
        int     isInputPsuedoLiteral(std::string& input);
        int     isInputNumber(std::string& input);
        void    castAndSet(t_type dt, std::string& input);
        // printers
        std::string printChar(void) const;
        std::string printInt(void) const;
        std::string printFloat(void) const;
        std::string printDouble(void) const;

void NewFunction(t_type dt, std::__1::string & input);
};

std::ostream &operator<<(std::ostream &os, const ScalarConverter &conv);
#endif // !SCALARCONVERTER_HPP
