#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : number_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int number) : number_(number << bits_) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float number) : number_(std::roundf(number * (1 << bits_))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed&	Fixed::operator=(const Fixed& fixed) {
	if (this != &fixed) {
		std::cout << "Copy assignment operator called" << std::endl;
		setRawBits(fixed.getRawBits());
	}
	return *this;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return number_;
}

void	Fixed::setRawBits(int const raw) {
	number_ = raw;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(number_) / (1 << bits_);
}

int	Fixed::toInt(void) const {
	return std::roundf(toFloat());
}

bool	Fixed::operator>(const Fixed& fixed) const {
	return this->number_ > fixed.number_;
}

bool	Fixed::operator<(const Fixed& fixed) const {
	return this->number_ < fixed.number_;
}

bool	Fixed::operator>=(const Fixed& fixed) const {
	return this->number_ >= fixed.number_;
}

bool	Fixed::operator<=(const Fixed& fixed) const {
	return this->number_ <= fixed.number_;
}

bool	Fixed::operator==(const Fixed& fixed) const {
	return this->number_ == fixed.number_;
}

bool	Fixed::operator!=(const Fixed& fixed) const {
	return this->number_ != fixed.number_;
}

Fixed	Fixed::operator+(const Fixed& fixed) const {
	Fixed	tmp;

	tmp.setRawBits(this->number_ + fixed.number_);
	return tmp;
}

Fixed	Fixed::operator-(const Fixed& fixed) const {
	Fixed	tmp;

	tmp.setRawBits(this->number_ - fixed.number_);
	return tmp;
}

Fixed	Fixed::operator*(const Fixed& fixed) const {
	long long	llnumber = this->number_;
	long long	simple_multiplied_llnumber = llnumber * fixed.number_;
	Fixed		tmp;

	tmp.setRawBits(std::roundf(simple_multiplied_llnumber / static_cast<float>(1 << bits_)));
	return tmp;
}

Fixed	Fixed::operator/(const Fixed& fixed) const {
	long long	llnumber = this->number_;
	long long	moved_point_llnumber = llnumber * (1 << bits_);
	Fixed		tmp;

	tmp.setRawBits(std::roundf(moved_point_llnumber / static_cast<float>(fixed.number_)));
	return tmp;
}

Fixed&	Fixed::operator++(void) {
	++number_;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	fixed = *this;
	++(*this);
	return fixed;
}

Fixed&	Fixed::operator--(void) {
	--number_;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	fixed = *this;
	--(*this);
	return fixed;
}

Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2) {
	if (fixed1 <= fixed2)
		return fixed1;
	return fixed2;
}

const Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1 <= fixed2)
		return fixed1;
	return fixed2;
}

Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2) {
	if (fixed1 <= fixed2)
		return fixed2;
	return fixed1;
}

const Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1 <= fixed2)
		return fixed2;
	return fixed1;
}

std::ostream&	operator<<(std::ostream& s, const Fixed& fixed) {
	return s << fixed.toFloat();
}
