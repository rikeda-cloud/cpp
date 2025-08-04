#include "easyfind.hpp"
#include "test.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <vector>

int main(void) {
  std::vector<int> vector;
  vector.push_back(1);
  vector.push_back(3);

  std::set<int> set;
  set.insert(1);
  set.insert(3);

  std::list<int> list;
  list.push_back(1);
  list.push_back(3);

  std::deque<int> deque;
  deque.push_back(1);
  deque.push_back(3);

  int fail_count = test_container(vector, "Vector", 1, true) +
                   test_container(vector, "Vector", 2, false) +
                   test_container(set, "Set", 1, true) +
                   test_container(set, "Set", 2, false) +
                   test_container(list, "List", 1, true) +
                   test_container(list, "List", 2, false) +
                   test_container(deque, "Deque", 1, true) +
                   test_container(deque, "Deque", 2, false);

  return fail_count != 0;
}
