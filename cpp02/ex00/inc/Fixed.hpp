#ifndef CPP02_EX00_Fixed_H_
# define CPP02_EX00_Fixed_H_

class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed&);
	~Fixed(void);
	Fixed&	operator=(const Fixed&);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					number_;
	const static int	bits_ = 8;
};

#endif
