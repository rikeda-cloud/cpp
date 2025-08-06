#include "MutantStack.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

void sample_main() {
  std::cout << "~~~ 課題PDFにあるサンプルのmain関数 ~~~" << std::endl;

  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void test_vector(void) {
  MutantStack<double, std::vector<double> > actual;
  actual.push(5.0);
  actual.push(17.0);
  actual.pop();
  actual.push(3.0);
  actual.push(5.0);
  actual.push(737.0);
  actual.push(0.0);

  std::vector<double> expect;
  expect.push_back(5.0);
  expect.push_back(17.0);
  expect.pop_back();
  expect.push_back(3.0);
  expect.push_back(5.0);
  expect.push_back(737.0);
  expect.push_back(0.0);

  if (!std::equal(actual.begin(), actual.end(), expect.begin())) {
    std::cout << "[ERROR] test_vector: content mismatch" << std::endl;
    return;
  }

  std::cout << "[OK]" << std::endl;
}

void test_list(void) {
  MutantStack<std::string, std::list<std::string> > actual;
  actual.push("5.0");
  actual.push("17.0");
  actual.pop();
  actual.push("3.0");
  actual.push("5.0");
  actual.push("737.0");
  actual.push("0.0");

  std::list<std::string> expect;
  expect.push_back("5.0");
  expect.push_back("17.0");
  expect.pop_back();
  expect.push_back("3.0");
  expect.push_back("5.0");
  expect.push_back("737.0");
  expect.push_back("0.0");

  if (!std::equal(actual.begin(), actual.end(), expect.begin())) {
    std::cout << "[ERROR] test_list: content mismatch" << std::endl;
    return;
  }

  std::cout << "[OK]" << std::endl;
}

void test_empty_stack(void) {
  MutantStack<int> empty_stack;

  for (MutantStack<int>::iterator it = empty_stack.begin();
       it != empty_stack.end(); it++) {
    std::cout << "[ERROR] test_empty_stack: Iterator is not working properly."
              << std::endl;
    return;
  }

  std::cout << "[OK]" << std::endl;
}

void test_one_content(void) {
  MutantStack<float> one_content;
  one_content.push(123.456f);

  unsigned cnt = 0;
  for (MutantStack<float>::iterator it = one_content.begin();
       it != one_content.end(); it++) {
    if (cnt > 0) {
      std::cout << "[ERROR] test_one_content: Iterator is not working properly."
                << std::endl;
      return;
    }
    cnt++;
  }
  if (cnt != 1) {
    std::cout << "[ERROR] test_one_content: Iterator is not working properly."
              << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;
}

int main(void) {
  sample_main();
  test_vector();
  test_list();
  test_empty_stack();
  test_one_content();
  return 0;
}
