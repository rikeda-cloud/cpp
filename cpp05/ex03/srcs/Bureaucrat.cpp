#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, size_t grade)
    : name_(name), grade_(grade) {
  if (grade < Bureaucrat::GRADE_HIGH_LIMIT) {
    throw Bureaucrat::GradeTooHighException();
  }
  if (grade > Bureaucrat::GRADE_LOW_LIMIT) {
    throw Bureaucrat::GradeTooLowException();
  }
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
    : name_(bureaucrat.name_), grade_(bureaucrat.grade_) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
  if (this != &bureaucrat) {
    const_cast<std::string &>(this->name_) = bureaucrat.name_;
    this->grade_ = bureaucrat.grade_;
  }
  return *this;
}

const std::string &Bureaucrat::getName(void) const { return this->name_; }

size_t Bureaucrat::getGrade(void) const { return this->grade_; }

void Bureaucrat::incrementGrade(void) {
  if (this->grade_ == GRADE_HIGH_LIMIT) {
    throw Bureaucrat::GradeTooHighException();
  }
  this->grade_--;
}

void Bureaucrat::decrementGrade(void) {
  if (this->grade_ == GRADE_LOW_LIMIT) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->grade_++;
}

std::string Bureaucrat::signForm(AForm &form) {
  std::string message;

  try {
    form.beSigned(*this);
    message = this->name_ + " signed " + form.getName() + "\n";
  } catch (std::exception &e) {
    message = this->name_ + " couldn't sign " + form.getName() + " because " +
              e.what() + ".\n";
  }

  std::cout << message;
  return message;
}

std::string Bureaucrat::executeForm(AForm const &form) const {
  std::string message;
  try {
    form.execute(*this);
    message = this->name_ + " executed " + form.getName() + "\n";
  } catch (std::exception &e) {
    message = this->name_ + " couldn't execute " + form.getName() +
              " because " + e.what() + "\n";
  }
  std::cout << message;
  return message;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}

std::ostream &operator<<(std::ostream &s, const Bureaucrat &bureaucrat) {
  return s << bureaucrat.getName() << ", bureaucrat grade "
           << bureaucrat.getGrade() << "." << std::endl;
}
