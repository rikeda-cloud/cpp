#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, size_t grade) : name_(name), grade_(grade) {
	if (grade < GRADE_HIGH_LIMIT)
		throw Bureaucrat::GradeTooHighException();
	if (GRADE_LOW_LIMIT < grade)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : name_(bureaucrat.name_), grade_(bureaucrat.grade_) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
	if (this != &bureaucrat) {
		const_cast<std::string&>(this->name_) = bureaucrat.name_;
		this->grade_ = bureaucrat.grade_;
	}
	return *this;
}

const std::string&	Bureaucrat::getName(void) const {
	return name_;
}

size_t	Bureaucrat::getGrade(void) const {
	return grade_;
}

void	Bureaucrat::GradeUp(size_t grade_increase) {
	if (GRADE_LOW_LIMIT <= grade_increase)
		throw Bureaucrat::GradeTooHighException();
	if (grade_ <= grade_increase)
		throw Bureaucrat::GradeTooHighException();
	grade_ -= grade_increase;
}

void	Bureaucrat::GradeDown(size_t grade_decrease) {
	if (GRADE_LOW_LIMIT <= grade_decrease)
		throw Bureaucrat::GradeTooLowException();
	if (GRADE_LOW_LIMIT <= grade_decrease + grade_)
		throw Bureaucrat::GradeTooLowException();
	grade_ += grade_decrease;
}

std::ostream&	operator<<(std::ostream& s, const Bureaucrat& bureaucrat) {
	return s << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
}
