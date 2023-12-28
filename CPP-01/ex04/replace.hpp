/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 02:55:43 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/28 04:02:07 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class Replace
{
    private:
        std::string _i_file;
        std::string _o_file;
    public:
        Replace(std::string i_file);
        ~Replace(void);
        void    replaceString(std::string s1, std::string s2);
};

#endif // !REPLACE_HPP