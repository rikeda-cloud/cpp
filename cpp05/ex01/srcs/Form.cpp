#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, size_t grade) : name_(name), is_signed_(false) {
	if (grade < GRADE_HIGH_LIMIT)
		throw Form::GradeTooHighException();
	if (GRADE_LOW_LIMIT < grade)
		throw Form::GradeTooLowException();
	grade_ = grade;
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& form) : name_(form.name_), grade_(form.grade_), is_signed_(form.is_signed_) {
	*this = form;
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(void) {
	std::cout << "Form destructor called" << std::endl;
}

Form&	Form::operator=(const Form& form) {
	if (this != &form) {
		this->name_ = form.name_;
		this->grade_ = form.grade_;
		this->is_signed_ = form.is_signed_;
	}
	return *this;
}

const std::string&	Form::getName(void) const {
	return name_;
}

size_t	Form::getGrade(void) const {
	return grade_;
}

bool	Form::getIsSigned(void) const {
	return is_signed_;
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (this->is_signed_)
		throw Form::AlreadySignedException();
	if (this->grade_ < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	is_signed_ = true;
}

std::ostream&	operator<<(std::ostream& s, const Form& form) {
	std::string	is_signed = form.getIsSigned() ? "True" : "False";

	return s << form.getName() << ", form grade " << form.getGrade() << ", form is_signed " << is_signed << std::endl;
}
