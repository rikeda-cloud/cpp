#include "MutantStack.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

struct Data {
  std::string str;
  int v;
};

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

void sample_main_std_list() {
  std::cout << "~~~ サンプルのmain関数をstd::listで置き換え ~~~" << std::endl;

  std::list<int> mstack;
  mstack.push_back(5);
  mstack.push_back(17);
  std::cout << mstack.back() << std::endl;
  mstack.pop_back();
  std::cout << mstack.size() << std::endl;
  mstack.push_back(3);
  mstack.push_back(5);
  mstack.push_back(737);
  //[...]
  mstack.push_back(0);
  std::list<int>::iterator it = mstack.begin();
  std::list<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int, std::list<int> > s(mstack);

  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void test_vector(void) {
  // std::vectorをstackの内部コンテナで使用
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
  // std::listをstackの内部コンテナで使用
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
  // 空のstackをイテレーションするケース
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
  // 要素数1のstackをイテレーションするケース
  MutantStack<float> one_content;
  one_content.push(123.456f);
  MutantStack<float>::iterator it = one_content.begin();

  ++it;
  if (it != one_content.end()) {
    std::cout << "[ERROR] test_one_content: Iterator is not working properly."
              << std::endl;
    return;
  }

  std::cout << "[OK]" << std::endl;
}

void test_copy_constructor(void) {
  // コピーコンストラクタが機能するか？ディープコピーか？
  MutantStack<int> stk1;
  stk1.push(1);
  stk1.push(2);
  stk1.push(3);

  MutantStack<int> stk2(stk1);

  if (stk1.size() != stk2.size() ||
      !std::equal(stk1.begin(), stk1.end(), stk2.begin())) {
    std::cout << "[ERROR] test_copy_constructor: Content/size mismatch"
              << std::endl;
    return;
  }

  stk1.pop();
  if (stk1.size() == stk2.size() || stk1.top() != 2 || stk2.top() != 3) {
    std::cout << "[ERROR] test_copy_constructor: shallow copy" << std::endl;
    return;
  }

  std::cout << "[OK]" << std::endl;
}

void test_assignment(void) {
  // 代入演算子が機能するか？ディープコピーか？
  MutantStack<std::string> stk1;
  stk1.push("1");
  stk1.push("2");

  MutantStack<std::string> stk2;
  stk2.push("X");
  stk2.push("Y");
  stk2.push("Z");

  stk2 = stk1;

  if (stk1.size() != stk2.size() ||
      !std::equal(stk1.begin(), stk1.end(), stk2.begin())) {
    std::cout << "[ERROR] test_assgnment: Content/size mismatch" << std::endl;
    return;
  }

  stk1.pop();
  if (stk1.size() == stk2.size() || stk1.top() != "1" || stk2.top() != "2") {
    std::cout << "[ERROR] test_assgnment: shallow copy" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;
}

void test_arrow_operator(void) {
  // アロー演算子でパラメータにアクセスできるか？
  MutantStack<Data> stk;

  Data d1 = {"Hello", 42};
  Data d2 = {"World", 100};

  stk.push(d1);
  stk.push(d2);

  MutantStack<Data>::iterator it = stk.begin();

  if (it->str != d1.str || it->v != d1.v) {
    std::cout << "[ERROR] test_arrow_operator: unexpect value" << std::endl;
    return;
  }
  it++;
  if (it->str != d2.str || it->v != d2.v) {
    std::cout << "[ERROR] test_arrow_operator: unexpect value" << std::endl;
    return;
  }
  --it;
  it->str = "NEW"; // INFO 値を変更可能
  it->v = 123;
  if (it->str != "NEW" || it->v != 123) {
    std::cout << "[ERROR] test_arrow_operator: unexpect value" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;
}

void test_rbegin_rend(void) {
  // rbegin()とrend()が機能するか？
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

  if (!std::equal(actual.rbegin(), actual.rend(), expect.rbegin())) {
    std::cout << "[ERROR] test_vector: content mismatch" << std::endl;
    return;
  }

  std::cout << "[OK]" << std::endl;
}

int main(void) {
  sample_main();
  sample_main_std_list();
  test_vector();
  test_list();
  test_empty_stack();
  test_one_content();
  test_copy_constructor();
  test_assignment();
  test_arrow_operator();
  test_rbegin_rend();
  return 0;
}
