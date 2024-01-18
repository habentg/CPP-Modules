/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 07:03:22 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/28 05:13:18 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// default constructor
Contact::Contact(void)
{
	return ;
}

// default destructor
Contact::~Contact(void)
{
	return ;
}

// setter funcitons -> clean way of setting the private data members
void	Contact::setFirstName(std::string first_name) { this->_first_name = first_name; }
void	Contact::setLastName(std::string last_name) { this->_last_name = last_name; }
void	Contact::setNickName(std::string nick_name) { this->_nick_name = nick_name; }
void	Contact::setPhoneNumber(std::string phonenum) { this->_phonenum = phonenum; }
void	Contact::setDarkSecret(std::string darkest_secret) { this->_darkest_secret = darkest_secret;}

// getter functions -> clean way of accessing the private data members
std::string	Contact::getFirstName(void) const { return (this->_first_name); }
std::string	Contact::getLastName(void) const { return (this->_last_name); }	
std::string	Contact::getNickName(void) const { return (this->_nick_name); }	
std::string	Contact::getDarkSecret(void) const { return (this->_darkest_secret); }
std::string	Contact::getPhoneNumber(void) const { return (this->_phonenum); }
