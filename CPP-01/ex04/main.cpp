/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 02:52:43 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/28 04:06:36 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Invalid num of parameters!!" << std::endl;
        std::cerr << "Usage: ./replace <filename> <to_find> <replace>" << std::endl;
        return (1);
    }
    Replace test(argv[1]);
    test.replaceString(argv[2], argv[3]);
}