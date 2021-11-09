/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:40:02 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/09 14:51:45 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << std::to_string(Account::getNbAccounts());
	std::cout << ";total:" << std::to_string(Account::getTotalAmount());
	std::cout << ";deposits:" << std::to_string(Account::getNbDeposits());
	std::cout << ";withdrawals:"  << std::to_string(Account::getNbWithdrawals());
	std::cout << std::endl;

}

Account::Account( int initial_deposit )
{

	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << std::to_string(this->_accountIndex);
	std::cout << ";amount:" << std::to_string(this->_amount);
	std::cout << ";created" << std::endl;

	Account::_nbAccounts += 1;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << std::to_string(this->_accountIndex);
	Account::checkAmount();
	std::cout << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << std::to_string(this->_accountIndex);
	std::cout << ";p_amount:" << std::to_string(this->_amount);
	std::cout << ";deposit:" << std::to_string(deposit);
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits +=1;
	Account::checkAmount();
	std::cout << ";nb_deposits:" << std::to_string(this->_nbDeposits);
	std::cout << std::endl;

}

bool	Account::makeWithdrawal( int withdrawal )
{
		Account::_displayTimestamp();
	std::cout << "index:" << std::to_string(this->_accountIndex);
	std::cout << ";p_amount:" << std::to_string(this->_amount);
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals +=1;
		std::cout << ";withdrawal:" << std::to_string(withdrawal);
		Account::checkAmount();
		std::cout << ";nb_withdrawals:" << std::to_string(this->_nbWithdrawals) << std::endl;
		return (true);
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return(false);
	}
}

int		Account::checkAmount( void ) const
{
	std::cout << ";amount:" << std::to_string(this->_amount);
	return(0);
}

void	Account::_displayTimestamp( void )
{
//	std::cout << "[19920104_091532] ";
struct timespec ts;
  struct tm t;

  clock_gettime(CLOCK_REALTIME, &ts);

  // No error return
  localtime_r(&ts.tv_sec, &t);

  std::cout << "[" << t.tm_year + 1900
            << t.tm_mon  + 1
            << t.tm_mday
			<< "_"
            << t.tm_hour
            << t.tm_min
            << t.tm_sec
			<< "] ";
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << std::to_string(this->_accountIndex);
	std::cout << ";amount:" << std::to_string(this->_amount);
	std::cout << ";deposits:" << std::to_string(this->_nbDeposits);
	std::cout << ";withdrawals:"  << std::to_string(this->_nbWithdrawals);
	std::cout << std::endl;
}

Account::Account( void )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << std::to_string(this->_accountIndex);
	Account::checkAmount();
	std::cout << ";created" << std::endl;

	Account::_nbAccounts += 1;
}
