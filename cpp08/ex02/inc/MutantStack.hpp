#ifndef CPP08_EX02_MutantStack_H_
# define CPP08_EX02_MutantStack_H_

#include <stack>

template<class T>
class MutantStack : public std::stack<T> {
public:
	MutantStack(void);
	MutantStack(const MutantStack& stack);
	~MutantStack(void);
	MutantStack&	operator=(const MutantStack& stack);

	// template<T>
	class iterator {
	public:
		T*	ptr_;

		iterator(const iterator&);
		~iterator(void);
		iterator&	operator=(const iterator&);

		T&			operator*(void);
		iterator&	operator++(void);
		iterator	operator++(int);
		iterator&	operator--(void);
		iterator	operator--(int);
		bool		operator!=(const iterator&);

	private:
		iterator(void);
	};

	iterator	begin(void);
	iterator	end(void);
};

#include <iostream>

template<class T>
MutantStack<T>::MutantStack(void) {}

template<class T>
MutantStack<T>::MutantStack(const MutantStack<T>& stack) : std::stack<T>(stack){
}

template<class T>
MutantStack<T>::~MutantStack(void) {
	std::cout << "delete MutantStack" << std::endl;
}

template<class T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& stack) {
	if (this != &stack) {
		*this = stack;
	}
	return *this;
}

// #include "MutantStack.tpp"

#endif
