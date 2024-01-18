/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:08:03 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/18 19:56:19 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

t_type ScalarConverter::getType(void) const {
    return this->_type;
}

bool    ScalarConverter::isImpossible(void) const {
    return this->_impossible;
}

int ScalarConverter::isInputPsuedoLiteral(const char* input) {
    if (!std::strcmp(input, "+inff") || !std::strcmp(input, "inff"))
        this->_type = PINFF;
    else if (!std::strcmp(input, "-inff"))
        this->_type = NINFF;
    else if (!std::strcmp(input, "nanf"))
        this->_type = NANNF;
    else if (!std::strcmp(input, "+inf") || !std::strcmp(input, "inf"))
        this->_type = PINF;
    else if (!std::strcmp(input, "-inf"))
        this->_type = NINF;
    else if (!std::strcmp(input, "nan"))
        this->_type = NANN;
    return this->_type;
}

void ScalarConverter::castAndSet(t_type dt, const char* input) {
    char* endPtr;

    if (dt == CHAR) {
        this->_char = input[0];
        this->_int = static_cast<int>(this->_char);
        this->_float = static_cast<float>(this->_char);
        this->_double = static_cast<double>(this->_char);
    } // done
    else if (dt == INT) {
        this->_int = std::strtol(input, &endPtr, 10);
        if (this->_int != std::strtol(input, &endPtr, 10)) {
            this->_impossible = true;
            return ;
        }
        if (this->_int <= 255 && this->_int >= 0)
            this->_char = static_cast<char>(this->_int);
        this->_float = static_cast<float>(this->_int);
        this->_double = static_cast<double>(this->_int);
    } // done
    else if (dt == FLOAT) {
        long i_long;
        this->_float = std::strtod(input, &endPtr);
        this->_int = -1;
        i_long = static_cast<long>(this->_float);
        if (i_long < INT_MAX && i_long > INT_MIN)
            this->_int = static_cast<int>(this->_float);
        if (this->_int <= 255 && this->_int >= 0)
            this->_char = static_cast<char>(this->_float);
        this->_double = static_cast<double>(this->_float);
    } // problem here
    else if (dt == DOUBLE) {
        this->_double = std::strtod(input, &endPtr);
        this->_int = -1;
        long i_long = static_cast<long>(this->_double);
        if (i_long < INT_MAX && i_long > INT_MIN)
            this->_int = static_cast<int>(this->_double);
        if (i_long <= 255 && i_long >= 0)
            this->_char = static_cast<char>(this->_double);
        this->_float = static_cast<float>(this->_double);
    } // done
}
void ScalarConverter::setNumberType(const char* input) {
    char* endPtr;
    std::strtod(input, &endPtr);
    if (*endPtr == 'f')
         this->_type = FLOAT;
    else if (std::strchr(input, '.'))
         this->_type = DOUBLE;
    else
        this->_type = INT;
}

bool    ft_checkf(const char *input)
{
    int count = 0;
    int i = 0;
    int f_index = 0;
    while (input[i])
    {
        if (input[i] == 'f'){
            f_index = i;
            count++;
        }
        if (count >= 2)
            return false;
        i++;
    }
    if (input[++f_index] != '\0' || (count && !std::strchr(input, '.')))
        return false;
    return true;
}
// we will set the type of the input we recieved
t_type ScalarConverter::setInputType(const char *input) {
    char* endPtr;  // Pointer to store the address of the first invalid character
    this->_type = UNKNOWN;

    if (input[1] == '\0')
        this->_type = CHAR;
    else if (isInputPsuedoLiteral(input))
        return (this->_type);
    std::strtod(input, &endPtr);
    if (*endPtr == '\0' || (*endPtr == 'f' && ft_checkf(input)))
        setNumberType(input);
    castAndSet(this->_type, input);
    return this->_type;
}
