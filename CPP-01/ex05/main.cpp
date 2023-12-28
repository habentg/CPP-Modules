/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 08:16:59 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/28 08:18:18 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void )
{
    Harl    harl;

    // harl.complain("DEBUG");
    // harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    return (0);
}