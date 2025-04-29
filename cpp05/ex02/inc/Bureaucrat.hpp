#ifndef CPP05_EX02_Bureaucrat_H_
#define CPP05_EX02_Bureaucrat_H_

#include <iostream>
#include <string>

class Form;

class Bureaucrat {
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

  Bureaucrat(std::string, size_t);
  Bureaucrat(const Bureaucrat &);
  ~Bureaucrat(void);
  Bureaucrat &operator=(const Bureaucrat &);

  const std::string &getName(void) const;
  size_t getGrade(void) const;
  void incrementGrade(void);
  void decrementGrade(void);
  std::string signForm(Form &);

private:
  const std::string name_;
  size_t grade_;

  Bureaucrat(void);
};

std::ostream &operator<<(std::ostream &s, const Bureaucrat &bureaucrat);

#endif
