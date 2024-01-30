#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//
Account::Account(int initial_deposit) : _accountIndex(Account::getNbAccounts()), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout
		<< " "
		<< "index:"
		<< _accountIndex
		<< ";"
		<< "amount:"
		<< _amount
		<< ";"
		<< "created"
		<< std::endl;
}

//
Account::Account(void) : _accountIndex(Account::getNbAccounts()), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
	Account::_nbAccounts++;
}

//
Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout
		<< " "
		<< "index:"
		<< _accountIndex
		<< ";"
		<< "amount:"
		<< _amount
		<< ";"
		<< "closed"
		<< std::endl;
}

//
int	Account::getNbAccounts(void) {
	return _nbAccounts;
}

//
int	Account::getTotalAmount(void) {
	return _totalAmount;
}

//
int	Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

//
int	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

//
void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout
		<< " "
		<< "accounts:"
		<< getNbAccounts()
		<< ";"
		<< "total:"
		<< getTotalAmount()
		<< ";"
		<< "deposits:"
		<< getNbDeposits()
		<< ";"
		<< "withdrawals:"
		<< getNbWithdrawals()
		<< std::endl;
}

//
void	Account::makeDeposit(int initial_deposit) {
	Account::_totalAmount += initial_deposit;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout
		<< " "
		<< "index:"
		<< _accountIndex
		<< ";"
		<< "p_amount:"
		<< _amount
		<< ";"
		<< "deposit:"
		<< initial_deposit
		<< ";";
	_amount += initial_deposit;
	_nbDeposits++;
	std::cout
		<< "amount:"
		<< _amount
		<< ";"
		<< "nb_deposits:"
		<< _nbDeposits
		<< std::endl;
}

//
bool	Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout
		<< " "
		<< "index:"
		<< _accountIndex
		<< ";"
		<< "p_amount:"
		<< _amount
		<< ";"
		<< "withdrawal:";
	if (_amount < withdrawal) {
		std::cout
			<< "refused"
			<< std::endl;
		return false;
	}
	else {
		Account::_totalNbWithdrawals++;
		_amount -= withdrawal;
		_nbWithdrawals++;
		std::cout
			<< withdrawal
			<< ";"
			<< "amount:"
			<< _amount
			<< ";"
			<< "nb_withdrawals:"
			<< _nbWithdrawals
			<< std::endl;
		return true;
	}
}

int	Account::checkAmount(void) const{
	return 0;
}

//
void	Account::displayStatus(void) const{
	Account::_displayTimestamp();
	std::cout
		<< " "
		<< "index:"
		<< _accountIndex
		<< ";"
		<< "amount:"
		<< _amount
		<< ";"
		<< "deposits:"
		<< _nbDeposits
		<< ";"
		<< "withdrawals:"
		<< _nbWithdrawals
		<< std::endl;
}

//
void	Account::_displayTimestamp(void) {
	time_t		current = time(NULL);
	struct tm	*local_time = localtime(&current);

	std::cout << "["
		<< local_time->tm_year
		<< local_time->tm_mon
		<< local_time->tm_mday
		<< "_"
		<< local_time->tm_hour
		<< local_time->tm_min
		<< local_time->tm_sec
		<< "]";
}
