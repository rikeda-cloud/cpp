#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : number_(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int int_number) : number_(int_number << bits_) {
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float float_number) : number_(std::roundf(float_number * (1 << bits_))) {
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed&	Fixed::operator=(const Fixed& fixed) {
	// std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(fixed.getRawBits());
	return *this;
}

int	Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return number_;
}

void	Fixed::setRawBits(int const raw) {
	number_ = raw;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(getRawBits()) / (1 << bits_);
}

int	Fixed::toInt(void) const {
	return getRawBits() / (1 << bits_);
}

bool	Fixed::operator>(const Fixed& fixed) const {
	return getRawBits() > fixed.getRawBits();
}

bool	Fixed::operator<(const Fixed& fixed) const {
	return getRawBits() < fixed.getRawBits();
}

bool	Fixed::operator>=(const Fixed& fixed) const {
	return getRawBits() >= fixed.getRawBits();
}

bool	Fixed::operator<=(const Fixed& fixed) const {
	return getRawBits() <= fixed.getRawBits();
}

bool	Fixed::operator==(const Fixed& fixed) const {
	return getRawBits() == fixed.getRawBits();
}

bool	Fixed::operator!=(const Fixed& fixed) const {
	return getRawBits() != fixed.getRawBits();
}

Fixed	Fixed::operator+(const Fixed& fixed) const {
	Fixed	tmp;
	tmp.setRawBits(getRawBits() + fixed.getRawBits());
	return tmp;
}

Fixed	Fixed::operator-(const Fixed& fixed) const {
	Fixed	tmp;
	tmp.setRawBits(getRawBits() - fixed.getRawBits());
	return tmp;
}

Fixed	Fixed::operator*(const Fixed& fixed) const {
	Fixed	tmp;
	tmp.setRawBits(getRawBits() * fixed.getRawBits() / (1 << bits_));
	return tmp;
}

Fixed	Fixed::operator/(const Fixed& fixed) const {
	Fixed	tmp;
	tmp.setRawBits((getRawBits() * (1 << bits_)) / fixed.getRawBits());
	return tmp;
}

Fixed&	Fixed::operator++(void) {
	setRawBits(getRawBits() + 1);
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	fixed = *this;
	++(*this);
	return fixed;
}

Fixed&	Fixed::operator--(void) {
	setRawBits(getRawBits() - 1);
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	fixed = *this;
	--(*this);
	return fixed;
}

Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2) {
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return fixed1;
	return fixed2;
}

Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return const_cast<Fixed&>(fixed1);
	return const_cast<Fixed&>(fixed2);
}

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2) {
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return fixed2;
	return fixed1;
}

Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return const_cast<Fixed&>(fixed2);
	return const_cast<Fixed&>(fixed1);
}

std::ostream&	operator<<(std::ostream& s, const Fixed& fixed) {
	return s << fixed.toFloat();
}
