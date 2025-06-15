#ifndef CPP08_EX01_Span_H_
#define CPP08_EX01_Span_H_

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
  unsigned int shortestSpan(void) const;
  unsigned int longestSpan(void) const;

private:
  unsigned int n_;
  unsigned int crr_idx_;
  unsigned int shortest_span_;
  unsigned int longest_span_;
  int *array_;

  unsigned int calcDiff(int, int) const;

  Span(void);
};

#endif
