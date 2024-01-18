/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hatesfam <hatesfam@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 05:51:14 by hatesfam          #+#    #+#             */
/*   Updated: 2023/12/27 02:40:07 by hatesfam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

// these variables are object-independent (static data members), 
// should be global to be accessible to all objects on the scope of the entire program
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* default constructor
    -> Initializing data members
    # eg. in this case one customer just came and opened an account in the bank.
*/ 
Account::Account(){
    Account::_displayTimestamp();
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = Account::_nbAccounts;
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
    Account::_nbAccounts++;
}

/* Parameterized constructor (constructor that accepts a parameter during the creating of the object)
    -> Initializing data members
    # eg. in this case one customer came to opened a bank account and he deposited some ammount right then.
*/ 
Account::Account( int initial_deposit ) {
    Account::_displayTimestamp();
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    this->_amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

/* Destructor
    -> end of an object (either deleted manually or autommatically called when the object is out of scope)
*/
Account::~Account() {
	_displayTimestamp();
	std::cout <<  " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

/* member function responsible of desplaying time in specific format */
void	Account::_displayTimestamp( void ) {
	time_t      rawtime;
	struct tm   *timeinfo;
	char        buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer;
}

/* member funciton responsible for desplaying the timestamp and some messagess
    -> its 'const' in its declaration so, nothing regarding the object status will be modified here
*/
void Account::displayStatus( void ) const {
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

/* member funciton of making a deposit
    -> receives an input, display the current time and the banking info of the user (object)
    -> add the deposit to the total ammount (of the object), && update the total amout in the bank (of the class).
    -> same for the number of deposits as well.
*/
void Account::makeDeposit( int deposit ) {
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

/*boolien member function that checks if withdrawall of specific ammount is possible
    -> if its not possible, print a message and return false.
    -> if possible, update important data members of both the object and the class, and return True.
*/
bool Account::makeWithdrawal( int withdrawal ) {
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
    if (withdrawal > this->_amount) {
        std::cout << "refused" << std::endl;
        return (false);
    }
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

void Account::displayAccountsInfos( void ) {
    Account::_displayTimestamp();
    std::cout << " accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

// returns the ammount of the current object. (this keyword)
int Account::checkAmount( void ) const { return this->_amount; }

// the following functions returns respective values of the static data members
// notice: we access them using the class itself, 
int Account::getNbAccounts(void) { return Account::_nbAccounts; }

int	Account::getTotalAmount( void ) { return Account::_totalAmount; }

int	Account::getNbDeposits( void ) { return Account::_totalNbDeposits; }

int	Account::getNbWithdrawals( void ) { return Account::_totalNbWithdrawals ; }
