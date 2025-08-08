#include "easyfind.hpp"
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

int test_return_first_find_pos(void) {
  int target_number = 42;
  const int actual_arr[] = {1, target_number, 2, target_number, 3};
  const int expect_arr[] = {target_number, 2, target_number, 3};
  std::vector<int> actual(actual_arr,
                          actual_arr + sizeof(actual_arr) / sizeof(int));
  std::vector<int> expect(expect_arr,
                          expect_arr + sizeof(expect_arr) / sizeof(int));
  std::vector<int>::const_iterator actual_it = easyfind(actual, target_number);
  std::vector<int>::const_iterator expect_it = expect.begin();

  for (; actual_it != actual.end(); ++actual_it, ++expect_it) {
    if (*expect_it != *actual_it) {
      std::cout << "[ERROR] test_return_first_find_pos: expect " << *expect_it
                << ", actual " << *actual_it << std::endl;
      return 1;
    }
  }
  std::cout << "[OK]" << std::endl;
  return 0;
}

int test_writeable(void) {
  int target_number = 42;
  int n = 10;
  const int actual_arr[] = {1, target_number, 3, 4, 5};
  const int expect_arr[] = {1, target_number * n, 3 * n, 4 * n, 5 * n};
  std::vector<int> actual(actual_arr,
                          actual_arr + sizeof(actual_arr) / sizeof(int));
  std::vector<int> expect(expect_arr,
                          expect_arr + sizeof(expect_arr) / sizeof(int));

  for (std::vector<int>::iterator it = easyfind(actual, target_number);
       it != actual.end(); ++it) {
    *it *= n;
  }

  std::vector<int>::const_iterator actual_it = actual.begin();
  std::vector<int>::const_iterator expect_it = expect.begin();
  for (; expect_it != expect.end(); expect_it++, actual_it++) {
    if (*expect_it != *actual_it) {
      std::cout << "[ERROR] test_writeable: expect " << *expect_it
                << ", actual " << *actual_it << std::endl;
      return 1;
    }
  }
  std::cout << "[OK]" << std::endl;
  return 0;
}

int test_unwriteable(void) {
  int target_number = 10;
  std::vector<int> expect;
  expect.push_back(target_number);
  expect.push_back(20);
  expect.push_back(30);
  const std::vector<int> actual(expect);
  std::vector<int>::const_iterator expect_it = easyfind(expect, 10);
  std::vector<int>::const_iterator actual_it = actual.begin();

  for (; actual_it != actual.end(); actual_it++, expect_it++) {
    if (*actual_it != *expect_it) {
      std::cout << "[ERROR] test_unwriteable: expect " << *expect_it
                << ", actual " << *actual_it << std::endl;
      return 1;
    }
  }
  std::cout << "[OK]" << std::endl;
  return 0;
}

int test_empty_container(void) {
  std::list<int> lst;
  std::list<int>::const_iterator it = easyfind(lst, 123);

  if (it != lst.end()) {
    std::cout << "[ERROR] test_empty_container: it no point end()."
              << std::endl;
    return 1;
  }
  std::cout << "[OK]" << std::endl;
  return 0;
}

int main(void) {

  int fail_count = test_vector() + test_set() + test_list() + test_deque() +
                   test_return_first_find_pos() + test_writeable() +
                   test_empty_container();
  return fail_count != 0;
}
