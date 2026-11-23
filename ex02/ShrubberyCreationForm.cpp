/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 21:41:39 by mrapp-he          #+#    #+#             */
/*   Updated: 2026/11/19 21:41:41 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (!file.is_open())
		throw (std::runtime_error("Unable to create shrubbery file"));
	for (int i = 0; i < 3; ++i) {
		file << TREE_1 << TREE_2 << TREE_3 << TREE_4 << TREE_5 << TREE_6 << TREE_7 << TREE_8 << TREE_9 << TREE_10;
		file << TREE_11 << TREE_12 << TREE_13 << TREE_14 << TREE_15 << TREE_16 << TREE_17 << TREE_18 << TREE_19 << TREE_20;
		file << TREE_21 << TREE_22 << TREE_23 << std::endl;
	}
	file.close();
}
