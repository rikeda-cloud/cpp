#ifndef CPP08_EX01_Span_H_
# define CPP08_EX01_Span_H_

#include <vector>

class Span {
public:
	~Span(void);
	Span(unsigned int);
	Span(const Span&);
	Span&	operator=(const Span&);

	void	addNumber(int);
	void	addNumber(std::vector<int>);
	void	addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
	int		shortestSpan(void) const;
	int		longestSpan(void) const;

private:
	std::vector<int>	vec_;
	unsigned int		capacity_;
	Span(void);
};

#endif
