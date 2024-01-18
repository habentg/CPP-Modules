/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:05:28 by hatesfam          #+#    #+#             */
/*   Updated: 2024/01/17 10:33:19 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
    Base* ptr = generate();
    identify(ptr); // accepts a ptr
    identify(*ptr); // accepts the object itself
    delete ptr;
}
