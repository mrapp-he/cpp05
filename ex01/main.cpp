/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 21:39:09 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/11/19 21:39:12 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat a;
		Bureaucrat b("Stalin", 1);
		Bureaucrat c(b);
		Bureaucrat d = b;

		std::cout << "Default Constructor: " << a << std::endl;
		std::cout << "Constructor: " << b << std::endl;
		std::cout << "Copy Constructor: " << c << std::endl;
		std::cout << "Overload Assign Operator: " << d;
		// b.incrementGrade(); //GradeTooHighException test
		// a.decrementGrade(); //GradeTooLowException test
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}