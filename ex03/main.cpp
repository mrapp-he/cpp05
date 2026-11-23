#include "Intern.hpp"

int main(void) {
	try {
		Bureaucrat a;
		Bureaucrat b("Stalin", 1);
		Bureaucrat c(b);
		Bureaucrat d = b;
		Bureaucrat robotExec("Robot", 45);
		Bureaucrat shrubExec("Gardener", 137);
		Bureaucrat president("President", 5);

		std::cout << "Default Constructor: " << a << std::endl;
		std::cout << "Constructor: " << b << std::endl;
		std::cout << "Copy Constructor: " << c << std::endl;
		std::cout << "Overload Assign Operator: " << d;

		Intern intern;
		AForm* rr = intern.makeForm("robotomy request", "Bender");
		AForm* sc = intern.makeForm("shrubbery creation", "home");
		AForm* pp = intern.makeForm("presidential pardon", "Alice");

		b.signForm(*rr);
		robotExec.executeForm(*rr);

		b.signForm(*sc);
		shrubExec.executeForm(*sc);

		b.signForm(*pp);
		president.executeForm(*pp);

		delete rr;
		delete sc;
		delete pp;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}