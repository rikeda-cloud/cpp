#ifndef CPP08_EX01_Span_H_
#define CPP08_EX01_Span_H_

#include <vector>

class Span {
public:
  Span(unsigned int);
  ~Span(void);
  Span(const Span &);
  Span &operator=(const Span &);

  void addNumber(int);
  template <typename Iter> void addNumbers(const Iter &first, const Iter &end) {
    for (Iter it = first; it != end; ++it) {
      addNumber(*it);
    }
  };
  unsigned int shortestSpan(void);
  unsigned int longestSpan(void);

private:
  unsigned int n_;
  std::vector<int> vec_;
  bool sorted_;

  void prepareCalcSpan(void);
  unsigned int calcDiff(int, int) const;

  Span(void);
};

#endif
