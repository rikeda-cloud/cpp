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

  // 毎回書くと長いのでtypedef
  typedef typename Container::iterator container_iterator;
  typedef typename Container::const_iterator container_const_iterator;

  // INFO bidirectional_iterator(双方向イテレータ) Interface的な役割
  // INFO [Iterator] https://cpprefjp.github.io/reference/iterator.html
  // INFO [Tag] https://cpprefjp.github.io/reference/iterator/iterator_tag.html
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

  class const_iterator
      : public std::iterator<std::bidirectional_iterator_tag, T> {
  private:
    container_const_iterator it_;

  public:
    const_iterator(void);
    const_iterator(container_const_iterator it);
    const_iterator(const const_iterator &other);
    ~const_iterator(void);
    const_iterator &operator=(const const_iterator &other);

    bool operator==(const const_iterator &other) const;
    bool operator!=(const const_iterator &other) const;

    const T &operator*(void) const;
    const T *operator->(void) const;

    const_iterator &operator++(void);
    const_iterator operator++(int);
    const_iterator &operator--(void);
    const_iterator operator--(int);
  };

  iterator begin(void);
  iterator end(void);
  const_iterator begin(void) const;
  const_iterator end(void) const;
};

#include "MutantStack.tpp"

#endif
