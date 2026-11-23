#ifndef INTERN_HPP
# define INTERN_HPP

# include <unordered_map>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	private:
		typedef AForm* (Intern::*FormCreator)(const std::string&) const;
		typedef std::unordered_map<std::string, FormCreator> FormCreatorMap;
		FormCreatorMap _formCreators;
		AForm* createShrubberyCreationForm(const std::string&) const;
		AForm* createRobotomyRequestForm(const std::string&) const;
		AForm* createPresidentialPardonForm(const std::string&) const;
	public:
		Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);
		~Intern();
		class FormNotFoundException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		AForm* makeForm(const std::string&, const std::string&) const;
};

#endif
