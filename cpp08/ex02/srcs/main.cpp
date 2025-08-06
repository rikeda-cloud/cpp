#include "MutantStack.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <list>

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

int main(void) {
  sample_main();
  test_vector();
  test_list();
  return 0;
}
