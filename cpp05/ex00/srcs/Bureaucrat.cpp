#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, size_t grade)
    : name_(name), grade_(grade) {
  if (grade < Bureaucrat::GRADE_HIGH_LIMIT) {
    throw Bureaucrat::GradeTooHighException();
  }
  if (grade > Bureaucrat::GRADE_LOW_LIMIT) {
    throw Bureaucrat::GradeTooLowException();
  }
  std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
    : name_(bureaucrat.name_), grade_(bureaucrat.grade_) {
  std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
  std::cout << "Bureaucrat destructor called" << std::endl;
}

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

std::ostream &operator<<(std::ostream &s, const Bureaucrat &bureaucrat) {
  return s << bureaucrat.getName() << ", bureaucrat grade "
           << bureaucrat.getGrade() << "." << std::endl;
}
