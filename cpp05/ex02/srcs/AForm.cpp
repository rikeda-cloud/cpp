#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, size_t grade_to_sign,
             size_t grade_to_execute)
    : name_(name), is_signed_(false), grade_to_sign_(grade_to_sign),
      grade_to_execute_(grade_to_execute) {
  if (grade_to_sign < AForm::GRADE_HIGH_LIMIT ||
      grade_to_execute < AForm::GRADE_HIGH_LIMIT) {
    throw AForm::GradeTooHighException();
  }
  if (grade_to_sign > AForm::GRADE_LOW_LIMIT ||
      grade_to_execute > AForm::GRADE_LOW_LIMIT) {
    throw AForm::GradeTooLowException();
  }
}

AForm::AForm(const AForm &form)
    : name_(form.name_), is_signed_(form.is_signed_),
      grade_to_sign_(form.grade_to_sign_),
      grade_to_execute_(form.grade_to_execute_) {}

AForm::~AForm(void) {}

AForm &AForm::operator=(const AForm &form) {
  if (this != &form) {
    const_cast<std::string &>(this->name_) = form.name_;
    const_cast<size_t &>(this->grade_to_sign_) = form.grade_to_sign_;
    const_cast<size_t &>(this->grade_to_execute_) = form.grade_to_execute_;
    this->is_signed_ = form.is_signed_;
  }
  return *this;
}

const std::string &AForm::getName(void) const { return this->name_; }

bool AForm::getIsSigned(void) const { return this->is_signed_; }

size_t AForm::getGradeToSign(void) const { return this->grade_to_sign_; }

size_t AForm::getGradeToExecute(void) const { return this->grade_to_execute_; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  // INFO すでにsign済みの場合も同様に処理

  if (this->grade_to_sign_ < bureaucrat.getGrade()) {
    throw AForm::GradeTooLowException();
  }
  this->is_signed_ = true;
}

void AForm::execute(Bureaucrat const &executor) const {
  if (is_signed_ == false)
    throw NoSignException();
  if (grade_to_execute_ < executor.getGrade())
    throw GradeTooLowException();
  action();
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}

const char *AForm::NoSignException::what() const throw() {
  return "form is not signed!";
}

std::ostream &operator<<(std::ostream &s, const AForm &form) {
  std::string is_signed = form.getIsSigned() ? "True" : "False";

  return s << "Name: " << form.getName() << std::endl
           << "Signed: " << is_signed << std::endl
           << "Grade to sign: " << form.getGradeToSign() << std::endl
           << "Grade to execute: " << form.getGradeToExecute() << std::endl;
}
