#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, size_t grade_to_sign, size_t grade_to_execute)
    : name_(name), is_signed_(false), grade_to_sign_(grade_to_sign),
      grade_to_execute_(grade_to_execute) {
  if (grade_to_sign < Form::GRADE_HIGH_LIMIT ||
      grade_to_execute < Form::GRADE_HIGH_LIMIT) {
    throw Form::GradeTooHighException();
  }
  if (grade_to_sign > Form::GRADE_LOW_LIMIT ||
      grade_to_execute > Form::GRADE_LOW_LIMIT) {
    throw Form::GradeTooLowException();
  }
}

Form::Form(const Form &form)
    : name_(form.name_), is_signed_(form.is_signed_),
      grade_to_sign_(form.grade_to_sign_),
      grade_to_execute_(form.grade_to_execute_) {}

Form::~Form(void) {}

Form &Form::operator=(const Form &form) {
  if (this != &form) {
    const_cast<std::string &>(this->name_) = form.name_;
    const_cast<size_t &>(this->grade_to_sign_) = form.grade_to_sign_;
    const_cast<size_t &>(this->grade_to_execute_) = form.grade_to_execute_;
    this->is_signed_ = form.is_signed_;
  }
  return *this;
}

const std::string &Form::getName(void) const { return this->name_; }

bool Form::getIsSigned(void) const { return this->is_signed_; }

const size_t Form::getGradeToSign(void) const { return this->grade_to_sign_; }

const size_t Form::getGradeToExecute(void) const {
  return this->grade_to_execute_;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
  // INFO すでにsign済みの場合も同様に処理

  if (this->grade_to_sign_ < bureaucrat.getGrade()) {
    throw Form::GradeTooLowException();
  }
  this->is_signed_ = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}

std::ostream &operator<<(std::ostream &s, const Form &form) {
  std::string is_signed = form.getIsSigned() ? "True" : "False";

  return s << "Name: " << form.getName() << std::endl
           << "Signed: " << is_signed << std::endl
           << "Grade to sign: " << form.getGradeToSign() << std::endl
           << "Grade to execute: " << form.getGradeToExecute() << std::endl;
}
