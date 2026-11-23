/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 21:39:23 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/11/19 21:39:26 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Example"), _signed(false), _sign_grade(150), _exec_grade(150) {}

Form::Form(const std::string& name, const int sign, const int exec) : _name(name), _signed(false), _sign_grade(sign), _exec_grade(exec) {}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade) {}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

const std::string& Form::getName() const {
	return (this->_name);
}

bool Form::getSignedState() const {
	return (this->_signed);
}

const int Form::getSignGrade() const {
	return (this->_sign_grade);
}

const int Form::getExecGrade() const {
	return (this->_exec_grade);
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw (GradeTooLowException());
}

std::ostream& operator<<(std::ostream& out, const Form& obj) {
	std::string state[2] = {"signed", "not signed"};
	out << obj.getName() << ", is " << state[obj.getSignedState()] << ", has a sign grade of " << obj.getSignGrade();
	out << " and a execute grade of " << obj.getExecGrade() << std::endl;
	return (out);
}