#ifndef CPP05_EX02_AForm_H_
#define CPP05_EX02_AForm_H_

#include <ostream>
#include <string>

class Bureaucrat;

class AForm {
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
  class NoSignException : public std::exception {
  public:
    const char *what() const throw();
  };

  AForm(const std::string &, size_t, size_t);
  AForm(const AForm &);
  virtual ~AForm(void);
  AForm &operator=(const AForm &);

  const std::string &getName(void) const;
  bool getIsSigned(void) const;
  size_t getGradeToSign(void) const;
  size_t getGradeToExecute(void) const;
  void beSigned(const Bureaucrat &);
  void execute(Bureaucrat const &) const;

private:
  const std::string name_;
  bool is_signed_;
  const size_t grade_to_sign_;
  const size_t grade_to_execute_;

  AForm(void);
  virtual void action(void) const = 0;
};

std::ostream &operator<<(std::ostream &s, const AForm &form);

#endif
