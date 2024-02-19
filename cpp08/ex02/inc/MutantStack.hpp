#ifndef CPP08_EX02_MutantStack_H_
# define CPP08_EX02_MutantStack_H_

#include <stack>
#include <deque>
#include <iterator>

template<class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	MutantStack(void);
	MutantStack(const MutantStack& stack);
	~MutantStack(void);
	MutantStack&	operator=(const MutantStack& stack);

	class iterator : public std::iterator<std::bidirectional_iterator_tag, T*> {
	public:
		iterator(T* ptr);
		iterator(const iterator&);
		~iterator(void);
		iterator&	operator=(const iterator&);

		T&			operator*(void);
		iterator&	operator++(void);
		iterator&	operator--(void);
		bool		operator!=(const iterator&) const;

	private:
		T*	ptr_;

		iterator(void);
	};

	iterator	begin(void);
	iterator	end(void);
};

#include "MutantStack.tpp"

#endif
