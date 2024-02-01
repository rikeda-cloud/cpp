

class Fixed {
private:
	int					number_;
	const static int	bits_ = 8;

public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed& fixed);
	Fixed&	operator=(const Fixed& fixed);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
