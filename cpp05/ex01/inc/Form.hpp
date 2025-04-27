#ifndef CPP05_EX01_Form_H_
#define CPP05_EX01_Form_H_

#include <ostream>
#include <string>

class Bureaucrat;

class Form {
public:
  static const size_t GRADE_HIGH_LIMIT = 1;
  static const size_t GRADE_LOW_LIMIT = 150;

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  Form(std::string, size_t, size_t);
  Form(const Form &);
  ~Form(void);
  Form &operator=(const Form &);

  const std::string &getName(void) const;
  bool getIsSigned(void) const;
  const size_t getGradeToSign(void) const;
  const size_t getGradeToExecute(void) const;
  void beSigned(const Bureaucrat &);

private:
  const std::string name_;
  bool is_signed_;
  const size_t grade_to_sign_;
  const size_t grade_to_execute_;

  Form(void);
};

std::ostream &operator<<(std::ostream &s, const Form &form);

#endif
