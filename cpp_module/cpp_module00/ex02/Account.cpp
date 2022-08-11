#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

Account::Account( int initial_deposit ) :
_accountIndex(_nbAccounts++),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0) {
	_displayTimestamp();
	_totalAmount += _amount;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	std::cout << ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits
		<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";withdrawal:";
	if (this->_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return 0;
	}else {
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;
		std::cout << withdrawal
			<< ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
		return 1;
	}
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::time_t	t = time(NULL);
	std::tm		*tm = localtime(&t);

	std::cout << "["
		<< std::setfill('0') << std::setw(4) << tm->tm_year + 1900
		<< std::setfill('0') << std::setw(2) << tm->tm_mon + 1
		<< std::setfill('0') << std::setw(2) << tm->tm_mday
		<< std::setw(1) << "_"
		<< std::setfill('0') << std::setw(2) << tm->tm_hour
		<< std::setfill('0') << std::setw(2) << tm->tm_min
		<< std::setfill('0') << std::setw(2) << tm->tm_sec
		<< "] ";
}

Account::Account( void ) {

}
