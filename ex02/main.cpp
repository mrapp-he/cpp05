/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 21:40:16 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/11/19 21:40:24 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

int main(void) {
	try {
		Bureaucrat a;
		Bureaucrat b("Stalin", 1);
		Bureaucrat c(b);
		Bureaucrat d = b;
		Bureaucrat robotExec("Robot", 45);
		Bureaucrat shrubExec("Gardener", 137);
		Bureaucrat president("President", 5);
		Bureaucrat lowExec("Intern", 60);

		std::cout << "Default Constructor: " << a << std::endl;
		std::cout << "Constructor: " << b << std::endl;
		std::cout << "Copy Constructor: " << c << std::endl;
		std::cout << "Overload Assign Operator: " << d;

		RobotomyRequestForm rr("Bender");
		b.signForm(rr);
		robotExec.executeForm(rr);

		ShrubberyCreationForm sc("home");
		b.signForm(sc);
		shrubExec.executeForm(sc);

		PresidentialPardonForm pp("Alice");
		b.signForm(pp);
		president.executeForm(pp);

		RobotomyRequestForm unsignedForm("Nobody");
		lowExec.executeForm(unsignedForm);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}