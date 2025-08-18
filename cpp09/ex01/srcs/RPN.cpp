#include "RPN.hpp"
#include "safecalc.hpp"
#include <cctype>
#include <exception>
#include <sstream>

int RPN::evaluate(const std::string &s) {
  std::istringstream iss(s);
  std::string token;
  std::stack<int> stk;

  while (iss >> token) {
    Operation op = detectOperation(token);
    doOperation(stk, op, token);
  }
  if (stk.size() != 1) {
    throw std::runtime_error("[ERROR] RPN.evaluate: RPN syntax");
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
    throw std::runtime_error(
        "[ERROR] RPN.detectOperation: detect unexpect token");
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
      throw std::runtime_error("[ERROR] RPN.doOperation: RPN syntax");
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
    return safe_add(v1, v2);
  case MINUS:
    return safe_diff(v1, v2);
  case DIV:
    return safe_div(v1, v2);
  case MUL:
    return safe_mul(v1, v2);
  default:
    throw std::runtime_error("[ERROR] RPN.calc: unexpect Operation");
  }
}
