#include "test.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <vector>

int test_vector(void) {
  std::vector<int> vector;
  vector.push_back(1);
  vector.push_back(3);

  return test_container(vector, "Vector", 1, true) +
         test_container(vector, "Vector", 2, false);
}

int test_set(void) {
  std::set<int> set;
  set.insert(1);
  set.insert(3);

  return test_container(set, "Set", 1, true) +
         test_container(set, "Set", 2, false);
}

int test_list(void) {
  std::list<int> list;
  list.push_back(1);
  list.push_back(3);

  return test_container(list, "List", 1, true) +
         test_container(list, "List", 2, false);
}

int test_deque(void) {
  std::deque<int> deque;
  deque.push_back(1);
  deque.push_back(3);

  return test_container(deque, "Deque", 1, true) +
         test_container(deque, "Deque", 2, false);
}

int main(void) {

  int fail_count = test_vector() + test_set() + test_list() + test_deque();
  return fail_count != 0;
}
