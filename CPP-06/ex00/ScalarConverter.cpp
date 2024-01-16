/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:20:14 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/15 19:09:24 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
    : _char('\0'), _int(0), _float(0.00f), _double(0.00), _type(UNKNOWN), _input(""), _impossible(false)
{ }

ScalarConverter::ScalarConverter(const ScalarConverter& cpy)
{
    *this = cpy;
}

ScalarConverter ScalarConverter::operator=(const ScalarConverter& rhs)
{
    if(this != &rhs)
    {
        this->_char = rhs._char;
        this->_int = rhs._int;
        this->_float = rhs._float;
        this->_double = rhs._double;
        this->_type = rhs._type;
        this->_input = rhs._input;
        this->_impossible = rhs._impossible;
    };
    return *this;
}

ScalarConverter::~ScalarConverter()
{ }

const char* ScalarConverter::UnknownType::whatCustom() const throw()
{
    return "\nError: Unknown Datatype\n\n   ->enter char, int, float or double!!\n";
}

void ScalarConverter::convert(std::string& input)
{
    ScalarConverter conv;

    conv._input = input;
    try {
        conv.setInputType(input);
        if (conv.getType() == UNKNOWN)
            throw ScalarConverter::UnknownType();
        std::cout << conv << std::endl; // if the datatpe is known, we diplay our casted values
    } catch (ScalarConverter::UnknownType &e)
    {
        std::cout << e.whatCustom() << std::endl;
    }
}
