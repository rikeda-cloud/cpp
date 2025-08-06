#ifndef CPP08_EX02_MutantStack_H_
#define CPP08_EX02_MutantStack_H_

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
  MutantStack(void);
  MutantStack(const MutantStack &other);
  ~MutantStack(void);
  MutantStack &operator=(const MutantStack &other);

  typedef typename Container::iterator container_iterator;

  class iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
  private:
    container_iterator it_;

  public:
    iterator(void);
    iterator(container_iterator it);
    iterator(const iterator &other);
    ~iterator(void);
    iterator &operator=(const iterator &other);

    bool operator==(const iterator &other) const;
    bool operator!=(const iterator &other) const;

    T &operator*(void) const;
    T *operator->(void) const;

    iterator &operator++(void);
    iterator operator++(int);
    iterator &operator--(void);
    iterator operator--(int);
  };

  iterator begin(void);
  iterator end(void);
};

#include "MutantStack.tpp"

#endif
