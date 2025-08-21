#ifndef CPP09_EX01_RPN_H_
#define CPP09_EX01_RPN_H_

#include <list>
#include <stack>
#include <string>

class RPN {
public:
  enum Operation { PLUS, MINUS, DIV, MUL, NUMBER };
  static int evaluate(const std::string &);

private:
  static Operation detectOperation(const std::string &);
  static void doOperation(std::stack<int, std::list<int> > &, Operation,
                          const std::string &);
  static int calc(int, int, Operation);

  static int safeAdd(int, int);
  static int safeSub(int, int);
  static int safeMul(int, int);
  static int safeDiv(int, int);

  RPN(void);
  ~RPN(void);
  RPN(const RPN &);
  RPN &operator=(const RPN &);
};

#endif
