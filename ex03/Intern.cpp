#include "Intern.hpp"

Intern::Intern() {
	_formCreators["shrubbery creation"] = &Intern::createShrubberyCreationForm;
	_formCreators["robotomy request"] = &Intern::createRobotomyRequestForm;
	_formCreators["presidential pardon"] = &Intern::createPresidentialPardonForm;
}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other)
		_formCreators = other._formCreators;
	return (*this);
}

Intern::~Intern() {}

const char* Intern::FormNotFoundException::what() const throw() {
	return ("Form not found!");
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) const {
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const {
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const {
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	FormCreatorMap::const_iterator iterator = _formCreators.find(formName);
	if (iterator != _formCreators.end()) {
		std::cout << "Intern creates " << formName << std::endl;
		return ((this->*(iterator->second))(target));
	}
	throw (FormNotFoundException());
}
