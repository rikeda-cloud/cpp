#ifndef CPP02_EX01_Fixed_H_
# define CPP02_EX01_Fixed_H_

#include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(int int_number);
	Fixed(float float_number);
	Fixed(const Fixed& fixed);
	~Fixed(void);
	Fixed&	operator=(const Fixed& fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					number_;
	const static int	bits_ = 8;
};

std::ostream&	operator<<(std::ostream& s, const Fixed& fixed);

#endif
