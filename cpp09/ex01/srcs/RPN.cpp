#include "RPN.hpp"
#include <cctype>
#include <exception>
#include <sstream>

RPN::RPN(void) {}

RPN::~RPN(void) {}

int RPN::evaluate(const std::string &s) {
  std::istringstream iss(s);
  std::string token;
  std::stack<int> stk;

  while (iss >> token) {
    Operation op = detectOperation(token);
    doOperation(stk, op, token);
  }
  if (stk.size() != 1) {
    throw std::exception();
  }
  return stk.top();
}

RPN::Operation RPN::detectOperation(const std::string &token) {
  if (token == "+") {
    return PLUS;
  } else if (token == "-") {
    return MINUS;
  } else if (token == "*") {
    return MUL;
  } else if (token == "/") {
    return DIV;
  } else if (token.size() == 1 && std::isdigit(token[0])) {
    return NUMBER;
  } else {
    throw std::exception();
  }
}

void RPN::doOperation(std::stack<int> &stk, Operation op,
                      const std::string &token) {
  switch (op) {
  case NUMBER:
    stk.push(static_cast<int>(token[0] - '0'));
    break;
  default:
    if (stk.size() < 2) {
      throw std::exception();
    }
    int first = stk.top();
    stk.pop();
    int second = stk.top();
    stk.pop();
    stk.push(calc(second, first, op));
  }
}

int RPN::calc(int v1, int v2, Operation op) {
  switch (op) {
  case PLUS:
    return v1 + v2;
  case MINUS:
    return v1 - v2;
  case DIV:
    if (v2 == 0) {
      // Division by zero is not allowed
      throw std::exception();
    }
    return v1 / v2;
  case MUL:
    return v1 * v2;
  default:
    throw std::exception();
  }
}
