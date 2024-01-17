/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:08:03 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/17 07:30:08 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

t_type ScalarConverter::getType(void) const {
    return this->_type;
}

int ScalarConverter::isInputPsuedoLiteral(std::string& input) {
    if (!input.compare("+inff") || !input.compare("inff"))
        this->_type = PINFF;
    if (!input.compare("-inff"))
        this->_type = NINFF;
    else if (!input.compare("+inf") || !input.compare("inf"))
        this->_type = PINF;
    else if (!input.compare("-inf"))
        this->_type = NINF;
    else if (!input.compare("nan"))
        this->_type = NANN;
    else if (!input.compare("nanf"))
        this->_type = NANNF;
    return this->_type;
}

double ft_setDouble(std::string& input) {
    
    double   doubleValue;
    try {
        doubleValue = std::stod(input);
    } catch (...)
    {
        return (-1);
    }
    return doubleValue;
}

float ft_setFloat(std::string& input) {
    float   floatValue;
    try {
        floatValue = std::stof(input);
    } catch (...)
    {
        return (-1);
    }
    return floatValue;
}

int ft_setInt(std::string& input) {
    int intValue;

    try {
        intValue = std::stoi(input);
    } catch (...)
    {
        return (-1);
    }
    return (intValue);
}

void ScalarConverter::castAndSet(t_type dt, std::string& input) {
    if (dt == CHAR) {
        this->_char = input[0];
        this->_int = static_cast<int>(this->_char);
        this->_float = static_cast<float>(this->_char);
        this->_double = static_cast<double>(this->_char);
    } // done
    else if (dt == INT) {
        this->_int = ft_setInt(input);
        try 
        {
            if (this->_int == -1 && std::stol(input))
            {
                this->_impossible = true;
                return ;
            }
            this->_char = static_cast<char>(this->_int);
            this->_float = static_cast<float>(this->_int);
            this->_double = static_cast<double>(this->_int);
        } catch (...)
        {
            this->_impossible = true;
        }
    } // done
    else if (dt == FLOAT) {
        this->_float = ft_setFloat(input);
        try 
        {
            if (this->_float == -1 && std::stod(input))
            {
                this->_impossible = true;
                return ;
            }
            this->_int = static_cast<int>(this->_float);
            if (static_cast<double>(INT_MAX - 1) - static_cast<double>(this->_float) < 0 || static_cast<double>(INT_MIN + 1) - static_cast<double>(this->_float) > 0)
                this->_int = -1;
            if (this->_int <= 255 && this->_int >= 0)
                this->_char = static_cast<char>(this->_float);
            this->_double = static_cast<double>(this->_float);
        } catch (...)
        {
            this->_impossible = true;
        }
    } // done
    else if (dt == DOUBLE) {
        this->_double = ft_setDouble(input);
        try 
        {
            if (this->_double == -1 && std::stod(input))
            {
                this->_impossible = true;
                return ;
            }
        } catch (...)
        {
            this->_impossible = true;
            return ;
        }
        this->_int = static_cast<int>(this->_double);
        if (static_cast<double>(INT_MAX - 1) - static_cast<double>(this->_double) < 0 || static_cast<double>(INT_MIN + 1) - static_cast<double>(this->_double) > 0)
                this->_int = -1;
        if (this->_int <= 255 && this->_int >= 0)
            this->_char = static_cast<char>(this->_double);
        this->_float = static_cast<float>(this->_double);
    } // kinda done ---- need some review    
}
int ScalarConverter::isInputNumber(std::string& input) {
    int dotCount = 0;
    size_t i = 0;
    if (!input.compare("."))
        return 0;
    if (input[0] == '-')
        i = 1;
    for (; i < input.length(); i++)
    {
        if (!std::isdigit(input[i]))
        {
            if (input[i] == '.' && dotCount < 2)
                dotCount++;
            else
                break ;
        }
    }
    if (i == input.length())
    {
        if (dotCount == 0)
            this->_type = INT;
        else if (dotCount == 1 && input[i -1 ] != '.')
            this->_type = DOUBLE;
    }
    else if (i == (input.length() - 1) && dotCount == 1 && input[i] == 'f' && input[input.length() - 2] != '.')
        this->_type = FLOAT;
    else
        return 0;
    castAndSet(this->_type, input);
    return 1;
}

int    ScalarConverter::setNumberType(std::string& input) {
    this->_type = UNKNOWN;
    if (isInputPsuedoLiteral(input))
        return (1);
    if (isInputNumber(input))
        return (1);
    return (0);
}

// we will set the type of the input we recieved
t_type ScalarConverter::setInputType(std::string& input) {
    this->_type = UNKNOWN;
    if (setNumberType(input))
        return this->_type;
    if (!std::isdigit(input[0]))
    {
        if (input[1] == '\0')
            this->_type = CHAR;
    }
    castAndSet(this->_type, input);
    return this->_type;
}