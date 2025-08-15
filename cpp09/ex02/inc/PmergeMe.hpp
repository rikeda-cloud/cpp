#ifndef CPP09_EX02_PmergeMe_H_
#define CPP09_EX02_PmergeMe_H_

#include <deque>
#include <vector>

class PmergeMe {
public:
  static std::vector<unsigned> sort(const std::vector<unsigned> &);
  static std::deque<unsigned> sort(const std::deque<unsigned> &);

private:
  PmergeMe(void);
  ~PmergeMe(void);
  PmergeMe(const PmergeMe &);
  PmergeMe &operator=(const PmergeMe &);
};

#endif
