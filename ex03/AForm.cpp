
#include "AForm.hpp"

AForm::AForm() : _name("Example"), _signed(false), _sign_grade(150), _exec_grade(150) {}

AForm::AForm(const std::string& name, const int sign, const int exec) : _name(name), _signed(false), _sign_grade(sign), _exec_grade(exec) {}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Form is not signed!");
}

const std::string& AForm::getName() const {
	return (this->_name);
}

bool AForm::getSignedState() const {
	return (this->_signed);
}

const int AForm::getSignGrade() const {
	return (this->_sign_grade);
}

const int AForm::getExecGrade() const {
	return (this->_exec_grade);
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw (GradeTooLowException());
}

void AForm::execute(const Bureaucrat& executor) const {
	if (!this->_signed)
		throw (FormNotSignedException());
	if (executor.getGrade() > this->_exec_grade)
		throw (GradeTooLowException());
	this->executeAction();
}

std::ostream& operator<<(std::ostream& out, const AForm& obj) {
	std::string state[2] = {"signed", "not signed"};
	out << obj.getName() << ", is " << state[obj.getSignedState()] << ", has a sign grade of " << obj.getSignGrade();
	out << " and a execute grade of " << obj.getExecGrade() << std::endl;
	return (out);
}