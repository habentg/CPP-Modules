/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:34:49 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/19 17:11:44 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

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
        ~A();
};

class B : public Base
{
    public:
        B();
        ~B();
};

class C : public Base
{
    public:
        C();
        ~C();
};

// methods
Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif // !BASE_HPP