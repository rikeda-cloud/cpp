#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <vector>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

bool test_vector(std::vector<int> v, int p, bool expect_find) {
  bool is_find = easyfind(v, p) != v.end();
  if (is_find == expect_find) {
    std::cout << GREEN << "[OK]" << RESET << std::endl;
    return false;
  } else {
    std::cout << RED << "[FAIL]"
              << " Vector:";
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
      std::cout << " " << *it;
    }
    std::cout << std::endl << "Param: " << p << RESET << std::endl;
    return true;
  }
}

bool test_set(std::set<int> s, int p, bool expect_find) {
  bool is_find = easyfind(s, p) != s.end();
  if (is_find == expect_find) {
    std::cout << GREEN << "[OK]" << RESET << std::endl;
    return false;
  } else {
    std::cout << RED << "[FAIL]"
              << " Set:";
    for (std::set<int>::const_iterator it = s.begin(); it != s.end(); ++it) {
      std::cout << " " << *it;
    }
    std::cout << std::endl << "Param: " << p << RESET << std::endl;
    return true;
  }
}

bool test_list(std::list<int> l, int p, bool expect_find) {
  bool is_find = easyfind(l, p) != l.end();
  if (is_find == expect_find) {
    std::cout << GREEN << "[OK]" << RESET << std::endl;
    return false;
  } else {
    std::cout << RED << "[FAIL]"
              << " List:";
    for (std::list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
      std::cout << " " << *it;
    }
    std::cout << std::endl << "Param: " << p << RESET << std::endl;
    return true;
  }
}

bool test_deque(std::deque<int> que, int p, bool expect_find) {
  bool is_find = easyfind(que, p) != que.end();
  if (is_find == expect_find) {
    std::cout << GREEN << "[OK]" << RESET << std::endl;
    return false;
  } else {
    std::cout << RED << "[FAIL]"
              << " Deque:";
    for (std::deque<int>::const_iterator it = que.begin(); it != que.end();
         ++it) {
      std::cout << " " << *it;
    }
    std::cout << std::endl << "Param: " << p << RESET << std::endl;
    return true;
  }
}

int main(void) {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(3);

  std::set<int> s;
  s.insert(1);
  s.insert(3);

  std::list<int> l;
  l.push_back(1);
  l.push_back(3);

  std::deque<int> d;
  d.push_back(1);
  d.push_back(3);

  int fail_count = test_vector(v, 1, true) + test_vector(v, 2, false) +
                   test_set(s, 1, true) + test_set(s, 2, false) +
                   test_list(l, 1, true) + test_list(l, 2, false) +
                   test_deque(d, 1, true) + test_deque(d, 2, false);

  return fail_count != 0;
}
