/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 02:57:56 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/28 04:42:52 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

// we will always have an input file so it should be provided while creation of the object.
Replace::Replace(std::string i_file) : _i_file(i_file)
{
    this->_o_file = i_file + ".replace";
    return ;   
};

Replace::~Replace(void)
{
    return ;   
};

/*
    -> we create an object for the input file (so we can get plenty of methods to manuplate it with)
    -> we open and read the entire content of it into one string (privilage compared to C)
    -> we search for exact first occurrence position of our 'find' and hold it somewhere for a sec.
    -> in a loop until we have no more occurence of 'find' in our entireFile content,
    -> push the entire content into the output file after the loop is done.
    -> properly close both of the files.
*/
void    Replace::replaceString(std::string find, std::string replce)
{
    std::ifstream   infile(this->_i_file);
    if (infile.is_open())
    {
        std::string entireFileContent;
        if (std::getline(infile, entireFileContent, '\0'))
        {
            std::ofstream   outfile(this->_o_file);
            size_t  occurrence = entireFileContent.find(find);
            while (occurrence != std::string::npos)
            {
                entireFileContent.erase(occurrence, find.length());
                entireFileContent.insert(occurrence, replce);
                occurrence = entireFileContent.find(find);
            }
            outfile << entireFileContent;
            outfile.close();
        }
        else
        {
            std::cerr << "ERROR: Empty Input file!" << std::endl;
            exit(1);            
        }
        infile.close();
    }
    else
    {
        std::cerr << "ERROR: Couldnt open Input file!" << std::endl;
        exit(1);
    }
};

