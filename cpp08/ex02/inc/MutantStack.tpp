#include <iostream>

template<class T, class Container>
MutantStack<T, Container>::MutantStack(void) {}

template<class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& stack) : std::stack<T>(stack){}

template<class T, class Container>
MutantStack<T, Container>::~MutantStack(void) {}

template<class T, class Container>
MutantStack<T, Container>&	MutantStack<T, Container>::operator=(const MutantStack<T, Container>& stack) {
	if (this != &stack) {
		*this = stack;
	}
	return *this;
}

template<class T, class Container>
MutantStack<T, Container>::iterator::iterator(T* ptr) : ptr_(ptr) {}

template<class T, class Container>
MutantStack<T, Container>::iterator::iterator(const iterator& it) : ptr_(it.ptr_) {}

template<class T, class Container>
MutantStack<T, Container>::iterator::~iterator(void) {}

template<class T, class Container>
typename MutantStack<T, Container>::iterator&	MutantStack<T, Container>::iterator::operator=(const iterator& it) {
	if (this != &it) {
		this->ptr_ = it.ptr_;
	}
	return *this;
}

template<class T, class Container>
T&	MutantStack<T, Container>::iterator::operator*(void) {
	return *ptr_;
}

template<class T, class Container>
typename MutantStack<T, Container>::iterator&	MutantStack<T, Container>::iterator::operator++(void) {
	ptr_++;
	return *this;
}

template<class T, class Container>
typename MutantStack<T, Container>::iterator&	MutantStack<T, Container>::iterator::operator--(void) {
	ptr_--;
	return *this;
}

template<class T, class Container>
bool	MutantStack<T, Container>::iterator::operator!=(const iterator& it) const {
	if (this->ptr_ != it.ptr_)
		return true;
	return false;
}

template<class T, class Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin(void) {
	return MutantStack<T, Container>::iterator(&this->c.front());
}

template<class T, class Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end(void) {
	return ++MutantStack<T, Container>::iterator(&this->c.back());
}
