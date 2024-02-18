#ifndef CPP08_EX02_MutantStack_H_
# define CPP08_EX02_MutantStack_H_

#include <stack>

template<class T>
class MutantStack {
public:
	MutantStack(void);
	MutantStack(const MutantStack&);
	~MutantStack(void);
	MutantStack&	operator=(const MutantStack&);

	T&		top(void) const;
	bool	empty(void) const;
	size_t	size(void) const;
	void	push(T);
	T		pop(void);
	MutantStack<T>*	begin(void);
	MutantStack<T>*	end(void);

	bool	operator==(const MutantStack&) const;
	bool	operator!=(const MutantStack&) const;
	bool	operator<(const MutantStack&) const;
	bool	operator<=(const MutantStack&) const;
	bool	operator>(const MutantStack&) const;
	bool	operator>=(const MutantStack&) const;

	template<T>
	class iterator {
	public:
		iterator(T* ptr) : ptr_(ptr) {};

	private:
		T*	ptr_;
	};


private:
	std::stack<T>	c;
};

#endif
