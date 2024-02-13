#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, size_t grade_to_sign, size_t grade_to_execute)
	:	name_(name),
		grade_to_sign_(grade_to_sign),
		grade_to_execute_(grade_to_execute),
		is_signed_(false) {
	if (grade_to_sign < GRADE_HIGH_LIMIT || grade_to_execute < GRADE_HIGH_LIMIT)
		throw AForm::GradeTooHighException();
	if (GRADE_LOW_LIMIT < grade_to_sign || GRADE_LOW_LIMIT < grade_to_execute)
		throw AForm::GradeTooLowException();
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm& form)
	:	name_(form.name_),
		grade_to_sign_(form.grade_to_sign_),
		grade_to_execute_(form.grade_to_execute_),
		is_signed_(form.is_signed_) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm(void) {
	std::cout << "AForm destructor called" << std::endl;
}

AForm&	AForm::operator=(const AForm& form) {
	if (this != &form) {
		const_cast<std::string&>(this->name_) = form.name_;
		const_cast<size_t&>(this->grade_to_sign_) = form.grade_to_sign_;
		const_cast<size_t&>(this->grade_to_execute_) = form.grade_to_execute_;
		this->is_signed_ = form.is_signed_;
	}
	return *this;
}

const std::string&	AForm::getName(void) const {
	return name_;
}

size_t	AForm::getGradeToSign(void) const {
	return grade_to_sign_;
}

size_t	AForm::getGradeToExecute(void) const {
	return grade_to_execute_;
}

bool	AForm::getIsSigned(void) const {
	return is_signed_;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (this->is_signed_)
		throw AForm::AlreadySignedException();
	if (this->grade_to_sign_ < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
	is_signed_ = true;
}

std::ostream&	operator<<(std::ostream& s, const AForm& form) {
	std::string	is_signed = form.getIsSigned() ? "True" : "False";

	return s <<form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute() << ", form is_signed " << is_signed << std::endl;
}

void	AForm::execute(Bureaucrat const& exeutor) const {
	if (is_signed_ == false)
		throw NoSignException();
	if (grade_to_execute_ < exeutor.getGrade())
		throw GradeTooLowException();
	Action();
}
