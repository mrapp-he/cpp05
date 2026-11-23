/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 21:39:14 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/11/19 21:39:19 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _exec_grade;
	public:
		Form();
		Form(const std::string&, const int, const int);
		Form(const Form&);
		Form& operator=(const Form&);
		~Form();
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		const std::string& getName() const;
		bool getSignedState() const;
		const int getSignGrade() const;
		const int getExecGrade() const;
		void beSigned(Bureaucrat&);
};

std::ostream& operator<<(std::ostream&, const Form&);

#endif