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
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(void) {
	return iterator(this->c.begin());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(void) {
	return iterator(this->c.end());
}

template<typename T, typename Container>
MutantStack<T, Container>::iterator::iterator(void) : it_() {}

template<typename T, typename Container>
MutantStack<T, Container>::iterator::iterator(container_iterator it) : it_(it) {}

template<typename T, typename Container>
MutantStack<T, Container>::iterator::iterator(const iterator &it) : it_(it.it_) {}

template<typename T, typename Container>
MutantStack<T, Container>::iterator::~iterator(void) {}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator &MutantStack<T, Container>::iterator::operator=(const iterator &it) {
	if (this != &it) {
		this->it_ = it.it_;
	}
	return *this;
}

template<typename T, typename Container>
bool MutantStack<T, Container>::iterator::operator==(const iterator &it) const {
	return this->it_ == it.it_;
}

template<typename T, typename Container>
bool MutantStack<T, Container>::iterator::operator!=(const iterator &it) const {
	return this->it_ != it.it_;
}

template<typename T, typename Container>
T &MutantStack<T, Container>::iterator::operator*(void) const {
	return *this->it_;
}

template<typename T, typename Container>
T *MutantStack<T, Container>::iterator::operator->(void) const {
	return &(*this->it_);
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator &MutantStack<T, Container>::iterator::operator++(void) {
	++this->it_;
	return *this;
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::iterator::operator++(int) {
	iterator tmp = *this;
	++this->it_;
	return tmp;
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator &MutantStack<T, Container>::iterator::operator--(void) {
	--this->it_;
	return *this;
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::iterator::operator--(int) {
	iterator tmp = *this;
	--this->it_;
	return tmp;
}
