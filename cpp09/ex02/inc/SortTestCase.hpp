#ifndef CPP09_EX02_SortTestCase_H_
#define CPP09_EX02_SortTestCase_H_

#include <vector>

class SortTestCase {
public:
  SortTestCase(const std::vector<unsigned>, std::size_t);
  ~SortTestCase();
  SortTestCase(const SortTestCase &);
  SortTestCase &operator=(const SortTestCase &);

  static std::vector<SortTestCase> createTestCase(void);
  static const std::size_t IGNORE_CMP = 99999;

  const std::vector<unsigned> &getInput() const;
  std::size_t getCmpCount() const;

private:
  std::vector<unsigned> input_;
  std::size_t expect_cmp_count_;

  SortTestCase(void);
};

#endif
