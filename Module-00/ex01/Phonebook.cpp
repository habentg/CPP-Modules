/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 06:31:24 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/28 11:20:20 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

// default constructor
PhoneBook::PhoneBook(void)
{
	return ;
}

// default destructor
PhoneBook::~PhoneBook(void)
{
	return ;
}

// intro message
void    PhoneBook::welcome(void) const
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << " Welcome to Crappy Awesome PhoneBook " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--------------USAGE FORMAT---------------" << std::endl;
    std::cout << std::endl;
    std::cout << "ADD\t: To add a contact." << std::endl;
    std::cout << std::endl;
    std::cout << "SEARCH\t: To search for a contact." << std::endl;
    std::cout << std::endl;
    std::cout << "EXIT\t: to exit the PhoneBook." << std::endl;
    std::cout << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

/***********************************************************************************************/
/*                                 ADD CONTACT                                                 */
/***********************************************************************************************/
int     PhoneBook::validateOthers(std::string input)
{
    int i = 0;

    while (input[i])
    {
        if (!(isalpha(input[i])))
        {
            std::cout << "Invalid input." << std::endl;
            return 1;
        }
        i++;
    }
    return 0;
}

int     PhoneBook::validatePhoneNum(std::string input)
{
    int i = 0;

    while (input[i])
    {
        if (!(isdigit(input[i])))
        {
            std::cout << "Invalid phone number." << std::endl;
            return 1;
        }
        i++;
    }
    return 0;
}
std::string  PhoneBook::acceptInput(std::string task)
{
    std::string  input;
    int    i = 1;

    while (i)
    {
        std::cout << std::endl;
        std::cout << task;
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout << "EOF - Invalid input." << std::endl;
            std::exit(1);
        }
        if (task == "Phone Number: ")
            i = PhoneBook::validatePhoneNum(input);
        else
            i = PhoneBook::validateOthers(input);
    }
    return input;
    
}

void    PhoneBook::addContact(int *contIndex)
{
    std::string fName;
	std::string lName;
	std::string nName;
	std::string phoneNum;
	std::string dSecret;

    fName = this->acceptInput("First Name: ");
    this->contacts[*contIndex % 8].setFirstName(fName);
    lName = this->acceptInput("Last Name: ");
    this->contacts[*contIndex % 8].setLastName(lName);
    nName = this->acceptInput("Nick Number: ");
    this->contacts[*contIndex % 8].setNickName(nName);
    phoneNum = this->acceptInput("Phone Number: ");
    this->contacts[*contIndex % 8].setPhoneNumber(phoneNum);
    dSecret = this->acceptInput("Darkest Secret: ");
    this->contacts[*contIndex % 8].setDarkSecret(dSecret);
    *contIndex += 1;
    std::cout << std::endl;
    std::cout << "Contact added successfully." << std::endl;
}

/***********************************************************************************************/
/*                                 SEARCH CONTACT                                              */
/***********************************************************************************************/

std::string	print_one_field(std::string inp)
{
	if (inp.length() > 9)
		return inp.substr(0, 8) + ".";
	else
		return inp;
}

void	PhoneBook::print_message(int i, std::string f_name, std::string l_name, std::string n_name) const
{
	std::cout << "|";
    std::cout << std::right << std::setw(10) << i << "|";
	std::cout << std::right << std::setw(10) << print_one_field(f_name) << "|";
	std::cout << std::right << std::setw(10) << print_one_field(l_name) << "|";
    std::cout  << std::right << std::setw(10) << print_one_field(n_name) << "|";
	std::cout << std::endl;
	std::cout << " ------------------------------------------- ";
	std::cout << std::endl;
}

int	PhoneBook::print_all() const {
	int	num = 0;
	int ret = 0;

	if ((this->contacts[num].getFirstName().empty()))
	{
		std::cout << "The Phone Book is empty!" << std::endl;
		ret = 1;
	}
	else
	{
		std::cout << " ------------------------------------------- " << std::endl;
		std::cout << "|     Index|" << "First Name|" << " Last Name|" << " Nick Name|" << std::endl;
		std::cout << " ------------------------------------------- " << std::endl;
		while (num < 8 && !(this->contacts[num].getFirstName().empty()))
		{
			print_message(num, this->contacts[num].getFirstName(), this->contacts[num].getLastName(), this->contacts[num].getNickName());
			num++;
		}
	}
	return (ret);
}

int accept_index(void)
{
    std::string  input;
    int     i = 1;

    while (i)
    {
        std::cout << "Enter index: ";
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout << "EOF - Invalid input. Exiting ...." << std::endl;
            std::exit(1);
        }
        if (input.length() > 1 || !(std::isdigit(input[0])) || (input[0] - '0') < 0 || (input[0] - '0') > 7)
        {
            std::cout << "Invalid input. try again ..." << std::endl;
            continue ;
        }
        i = 0;
    }
    return (input[0] - '0');
}

void PhoneBook::print_contact(int num) const
{
    std::cout << "╔═══════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                         CONTACT CARD                      ║" << std::endl;
    std::cout << "╠═════════════════╦═════════════════════════════════════════╣" << std::endl;
    std::cout << "║ First Name     :║ " << std::left << std::setw(40) << this->contacts[num].getFirstName() << "║" << std::endl;
    std::cout << "╠═════════════════╬═════════════════════════════════════════╣" << std::endl;
    std::cout << "║ Last Name      :║ " << std::left << std::setw(40) << this->contacts[num].getLastName() << "║" << std::endl;
    std::cout << "╠═════════════════╬═════════════════════════════════════════╣" << std::endl;
    std::cout << "║ Nick Name      :║ " << std::left << std::setw(40) << this->contacts[num].getNickName() << "║" << std::endl;
    std::cout << "╠═════════════════╬═════════════════════════════════════════╣" << std::endl;
    std::cout << "║ Phone Number   :║ " << std::left << std::setw(40) << this->contacts[num].getPhoneNumber() << "║" << std::endl;
    std::cout << "╠═════════════════╬═════════════════════════════════════════╣" << std::endl;
    std::cout << "║ Darkest secret :║ " << std::left << std::setw(40) << this->contacts[num].getDarkSecret() << "║" << std::endl;
    std::cout << "╚═════════════════╩═════════════════════════════════════════╝" << std::endl;
}

void PhoneBook::searchContact(void) const
{
    int i = 1;

    if (this->print_all() == 1)
        return ;
    while (i)
    {
        int index = accept_index();
        if (this->contacts[index].getFirstName().empty())
        {
            std::cout << "Invalid index. Try again ..." << std::endl;
            continue ;
        }
        print_contact(index);
        i = 0;
    }
}