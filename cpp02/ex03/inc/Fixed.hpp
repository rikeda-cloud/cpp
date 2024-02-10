#ifndef CPP02_EX03_Fixed_H_
# define CPP02_EX03_Fixed_H_

#include <iostream>

class Fixed {
private:
	int					number_;
	const static int	bits_ = 8;

public:
	Fixed(void);
	Fixed(int);
	Fixed(float);
	~Fixed(void);
	Fixed(const Fixed& fixed);
	Fixed&	operator=(const Fixed& fixed);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator>(const Fixed& fixed) const;
	bool	operator<(const Fixed& fixed) const;
	bool	operator>=(const Fixed& fixed) const;
	bool	operator<=(const Fixed& fixed) const;
	bool	operator==(const Fixed& fixed) const;
	bool	operator!=(const Fixed& fixed) const;

	Fixed	operator+(const Fixed& fixed) const;
	Fixed	operator-(const Fixed& fixed) const;
	Fixed	operator*(const Fixed& fixed) const;
	Fixed	operator/(const Fixed& fixed) const;

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	static Fixed&		min(Fixed& fixed1, Fixed& fixed2);
	static const Fixed&	min(const Fixed& fixed1, const Fixed& fixed2);
	static Fixed&		max(Fixed& fixed1, Fixed& fixed2);
	static const Fixed&	max(const Fixed& fixed1, const Fixed& fixed2);
};

std::ostream&	operator<<(std::ostream& s, const Fixed& fixed);

#endif
