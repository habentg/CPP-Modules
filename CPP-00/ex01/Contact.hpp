/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 06:21:07 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/28 05:04:49 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string _phonenum;
		std::string	_darkest_secret;

	public:
		Contact(void);
		~Contact(void);
		// setter function prototypes
		void	setFirstName(std::string first_name);
		void	setLastName(std::string last_name);
		void	setNickName(std::string nick_name);
		void	setPhoneNumber(std::string phonenum);
		void	setDarkSecret(std::string darkest_secret);
		// getter function prototypes
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickName(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkSecret(void) const;
};
#endif