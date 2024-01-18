/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:34:49 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/17 10:38:42 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string>
#include <cstdint>
#include <cstdlib>
#include <ctime>

// typedef unsigned int uintptr_t;

class Base
{
    public:
        // Base();
        virtual ~Base();
};

class A : public Base
{
    public:
        A();
        virtual ~A();
};

class B : public Base
{
    public:
        B();
        virtual ~B();
};

class C : public Base
{
    public:
        C();
        virtual ~C();
};

// methods
Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif // !BASE_HPP