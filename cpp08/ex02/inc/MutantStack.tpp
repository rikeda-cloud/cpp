#include <iostream>
#include <stack>

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(void) {}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& stack) : std::stack<T>(stack){}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void) {}

template<typename T, typename Container>
MutantStack<T, Container>&	MutantStack<T, Container>::operator=(const MutantStack<T, Container>& stack) {
	if (this != &stack) {
		std::stack<T, Container>::operator=(stack);
	}
	return *this;
}

template<typename T, typename Container>
MutantStack<T, Container>::iterator::iterator(T* ptr) : ptr_(ptr) {}

template<typename T, typename Container>
MutantStack<T, Container>::iterator::iterator(const iterator& it) : ptr_(it.ptr_) {}

template<typename T, typename Container>
MutantStack<T, Container>::iterator::~iterator(void) {}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator&	MutantStack<T, Container>::iterator::operator=(const iterator& it) {
	if (this != &it) {
		this->ptr_ = it.ptr_;
	}
	return *this;
}

template<typename T, typename Container>
T&	MutantStack<T, Container>::iterator::operator*(void) {
	return *ptr_;
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator&	MutantStack<T, Container>::iterator::operator++(void) {
	ptr_++;
	return *this;
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator&	MutantStack<T, Container>::iterator::operator--(void) {
	ptr_--;
	return *this;
}

template<typename T, typename Container>
bool	MutantStack<T, Container>::iterator::operator!=(const iterator& it) const {
	if (this->ptr_ != it.ptr_)
		return true;
	return false;
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin(void) {
	return MutantStack<T, Container>::iterator(&this->c.front());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end(void) {
	return ++MutantStack<T, Container>::iterator(&this->c.back());
}
