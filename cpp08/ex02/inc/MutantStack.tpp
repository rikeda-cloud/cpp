template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>() {}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& stack) : std::stack<T, Container>(stack) {}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void) {}

template<typename T, typename Container>
MutantStack<T, Container>&	MutantStack<T, Container>::operator=(const MutantStack<T, Container>& stack) {
	if (this != &stack) {
		this->c = stack.c;
	}
	return *this;
}

template<typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::begin(void) {
	return this->c.begin();
}

template<typename T, typename Container>
typename Container::reverse_iterator MutantStack<T, Container>::rbegin(void) {
	return this->c.rbegin();
}

template<typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end(void) {
	return this->c.end();
}

template<typename T, typename Container>
typename Container::reverse_iterator MutantStack<T, Container>::rend(void) {
	return this->c.rend();
}
