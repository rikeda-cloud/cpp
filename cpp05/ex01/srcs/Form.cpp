#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, size_t grade_to_sign, size_t grade_to_excecute)
	:	name_(name),
		grade_to_sign_(grade_to_sign),
		grade_to_excecute_(grade_to_excecute),
		is_signed_(false) {
	if (grade_to_sign < GRADE_HIGH_LIMIT || grade_to_excecute < GRADE_HIGH_LIMIT)
		throw Form::GradeTooHighException();
	if (GRADE_LOW_LIMIT < grade_to_sign || GRADE_LOW_LIMIT < grade_to_excecute)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& form)
	:	name_(form.name_),
		grade_to_sign_(form.grade_to_sign_),
		grade_to_excecute_(form.grade_to_excecute_),
		is_signed_(form.is_signed_) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(void) {
	std::cout << "Form destructor called" << std::endl;
}

Form&	Form::operator=(const Form& form) {
	if (this != &form) {
		const_cast<std::string&>(this->name_) = form.name_;
		const_cast<size_t&>(this->grade_to_sign_) = form.grade_to_sign_;
		const_cast<size_t&>(this->grade_to_excecute_) = form.grade_to_excecute_;
		this->is_signed_ = form.is_signed_;
	}
	return *this;
}

const std::string&	Form::getName(void) const {
	return name_;
}

size_t	Form::getGradeToSign(void) const {
	return grade_to_sign_;
}

size_t	Form::getGradeToExcecute(void) const {
	return grade_to_excecute_;
}

bool	Form::getIsSigned(void) const {
	return is_signed_;
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (this->is_signed_)
		throw Form::AlreadySignedException();
	if (this->grade_to_sign_ < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	is_signed_ = true;
}

std::ostream&	operator<<(std::ostream& s, const Form& form) {
	std::string	is_signed = form.getIsSigned() ? "True" : "False";

	return s <<form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExcecute() << ", form is_signed " << is_signed << std::endl;
}
