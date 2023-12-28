/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 06:31:58 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/27 06:20:01 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
#include <iomanip>

class PhoneBook
{
	private:
		Contact		contacts[8];
	public:
		PhoneBook(void);
		~PhoneBook( void );
		// member functions
		void    	welcome(void) const;
		void    	addContact(int *contIndex);
		void		searchContact(void) const;
	
		// helper functions
		std::string	acceptInput(std::string task);
		int			validatePhoneNum(std::string input);
		int     	validateOthers(std::string input);
		int			print_all() const;
		void		print_message(int i, std::string f_name, std::string l_name, std::string n_name) const;
		void 		print_contact(int num) const;
};
#endif