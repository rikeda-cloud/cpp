#ifndef CPP09_EX02_PmergeMe_H_
#define CPP09_EX02_PmergeMe_H_

class PmergeMe {
public:
  static unsigned jacobsthal(unsigned);

private:
  PmergeMe(void);
  ~PmergeMe(void);
  PmergeMe(const PmergeMe &);
  PmergeMe &operator=(const PmergeMe &);
};

#endif
