#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void) : _accountIndex(Account::getNbAccounts()), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(Account::getNbAccounts()), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts(void) {
	return _nbAccounts;
}

int	Account::getTotalAmount(void) {
	return _totalAmount;
}

int	Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int initial_deposit) {
	Account::_totalAmount += initial_deposit;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << initial_deposit;
	_amount += initial_deposit;
	_nbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	bool	is_can_withdrawal = (withdrawal < _amount);

	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (is_can_withdrawal) {
		Account::_totalNbWithdrawals++;
		_nbWithdrawals++;
		_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals;
	}
	else
		std::cout << "refused";
	std::cout << std::endl;
	return is_can_withdrawal;
}

int	Account::checkAmount(void) const{
	return _amount;
}

void	Account::displayStatus(void) const{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void) {
	time_t		current = time(NULL);
	struct tm	*local_time = localtime(&current);

	std::cout << "[";
	std::cout << local_time->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_sec;
	std::cout << "]";
}
