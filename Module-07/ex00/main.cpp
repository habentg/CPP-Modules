/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:17:31 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/19 14:39:40 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

// (::) demo
// namespace example {
//     template<typename T>
//     void   swap(T val_1, T val_2) // passing by value (we do our thing on copies of the original values)
//     {
//         T tmp = val_1;
//         val_1 = val_2;
//         val_2 = tmp;
//     }
// }

// scope resolution operator (::)
    // we are using (::) because our functions are declared globaly (thy are not part of a namespace/class).
int main( void ) {
    int a = 2;
    int b = 3;
    
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}

/* templates:
     -> creating a generic code (function, class ...) thats not limited to only one datatype
     -> the function/class is non-existent until its called.
     -> upon calling the function, the compiler just generates a code that resembles the template by substiuting the datatypes.
     -> has some rules and requirements for parameters you are passing:
        # if you are passing by value, the objects (the type) should be copyable. (if not you get incomphensible error mesage)
        # the parameters you are passing should adhere to the computation you are doing inside that function.
     NOTE: these rules are prolly why its not encouraged to use tamplates excessibely
         -> incase of compilation error, the error message is comming from std library's ... not easy to undersand. */