
#ifndef A_FORM_HPP
# define A_FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _exec_grade;
	protected:
		virtual void executeAction() const = 0;
	public:
		AForm();
		AForm(const std::string&, const int, const int);
		AForm(const AForm&);
		AForm& operator=(const AForm&);
		~AForm();
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		const std::string& getName() const;
		bool getSignedState() const;
		const int getSignGrade() const;
		const int getExecGrade() const;
		void beSigned(Bureaucrat&);
		void execute(const Bureaucrat&) const;
};

std::ostream& operator<<(std::ostream&, const AForm&);

#endif