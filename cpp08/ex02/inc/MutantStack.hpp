#ifndef CPP08_EX02_MutantStack_H_
#define CPP08_EX02_MutantStack_H_

#include <deque>
#include <stack>

// INFO 内部で使用するコンテナを指定しない場合、dequeを使用
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
  MutantStack(void);
  MutantStack(const MutantStack &);
  ~MutantStack(void);
  MutantStack &operator=(const MutantStack &);

  typedef typename Container::iterator iterator;
  typedef typename Container::reverse_iterator reverse_iterator;

  iterator begin(void);
  reverse_iterator rbegin(void);
  iterator end(void);
  reverse_iterator rend(void);
};

#include "MutantStack.tpp"

#endif
