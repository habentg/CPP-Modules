/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 04:39:11 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/28 05:06:00 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phonebook.hpp"

int main(void)
{
	PhoneBook   phonebook;
	std::string 		input;
	int 		contIndex = 0;

	phonebook.welcome();
	while (1)
	{
		std::cout << "Input: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (input.compare("ADD") == 0)
			phonebook.addContact(&contIndex);
		else if (input.compare("SEARCH") == 0)
			phonebook.searchContact();
		else if (input.compare("EXIT") == 0)
		{
			std::cout << "Exiting PhoneBook..." << std::endl;
			break ;
		}
		else
			std::cout << "Invalid input." << std::endl;
		std::cout << std::endl;
	}
	return (0);
}