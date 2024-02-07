#ifndef CPP02_EX00_Fixed_H_
# define CPP02_EX00_Fixed_H_

class Fixed {
private:
	int					number_;
	const static int	bits_ = 8;

public:
	Fixed(void);
	Fixed(const Fixed& fixed);
	~Fixed(void);
	Fixed&	operator=(const Fixed& fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
