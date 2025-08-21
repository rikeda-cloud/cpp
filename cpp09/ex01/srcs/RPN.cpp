#include "RPN.hpp"
#include <limits>
#include <list>
#include <sstream>

int RPN::evaluate(const std::string &s) {
  std::istringstream iss(s);
  std::string token;
  std::stack<int, std::list<int> > stk;

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

void RPN::doOperation(std::stack<int, std::list<int> > &stk, Operation op,
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
    return safeAdd(v1, v2);
  case MINUS:
    return safeSub(v1, v2);
  case DIV:
    return safeDiv(v1, v2);
  case MUL:
    return safeMul(v1, v2);
  default:
    throw std::runtime_error("[ERROR] RPN.calc: unexpect Operation");
  }
}

int RPN::safeAdd(int v1, int v2) {
  if (v2 > 0 && v1 > std::numeric_limits<int>::max() - v2) {
    throw std::runtime_error("[ERROR] safeAdd: Overflow");
  }
  if (v2 < 0 && v1 < std::numeric_limits<int>::min() - v2) {
    throw std::runtime_error("[ERROR] safeAdd: Underflow");
  }
  return v1 + v2;
}

int RPN::safeSub(int v1, int v2) {
  if (v2 < 0 && v1 > std::numeric_limits<int>::max() + v2) {
    throw std::runtime_error("[ERROR] safeSub: Overflow");
  }
  if (v2 > 0 && v1 < std::numeric_limits<int>::min() + v2) {
    throw std::runtime_error("[ERROR] safeSub: Underflow");
  }
  return v1 - v2;
}

int RPN::safeDiv(int v1, int v2) {
  if (v2 == 0) {
    throw std::runtime_error("[ERROR] safeDiv: 0 div");
  }
  if (v1 == std::numeric_limits<int>::min() && v2 == -1) {
    throw std::runtime_error("[ERROR] safeDiv: Floating point exception");
  }
  return v1 / v2;
}

int RPN::safeMul(int v1, int v2) {
  // INFO https://www.jpcert.or.jp/sc-rules/c-int32-c.html
  if (v1 > 0) {
    if (v2 > 0) {
      if (v1 > (std::numeric_limits<int>::max() / v2)) {
        throw std::runtime_error("[ERROR] safeMul: Overflow");
      }
    } else {
      if (v2 < (std::numeric_limits<int>::min() / v1)) {
        throw std::runtime_error("[ERROR] safeMul: Underflow");
      }
    }
  } else {
    if (v2 > 0) {
      if (v1 < (std::numeric_limits<int>::min() / v2)) {
        throw std::runtime_error("[ERROR] safeMul: Underflow");
      }
    } else {
      if ((v1 != 0) && (v2 < (std::numeric_limits<int>::max() / v1))) {
        throw std::runtime_error("[ERROR] safeMul: Overflow");
      }
    }
  }
  return v1 * v2;
}
