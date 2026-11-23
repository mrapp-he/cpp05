/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 21:39:34 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/11/19 21:39:38 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Joe"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (this->_grade < 1)
		throw (GradeTooHighException());
	else if (this->_grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	if (this->_grade < 1)
		throw (GradeTooHighException());
	else if (this->_grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		this->_grade = other._grade;
	if (this->_grade < 1)
		throw (GradeTooHighException());
	else if (this->_grade > 150)
		throw (GradeTooLowException());
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

const std::string& Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	this->_grade--;
	if (this->_grade < 1)
		throw (GradeTooHighException());
	else if (this->_grade > 150)
		throw (GradeTooLowException());
}

void Bureaucrat::decrementGrade() {
	this->_grade++;
	if (this->_grade < 1)
		throw (GradeTooHighException());
	else if (this->_grade > 150)
		throw (GradeTooLowException());
}

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return (out);
}