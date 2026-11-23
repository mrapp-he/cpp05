
#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string _target;
	protected:
		void executeAction() const;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string&);
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm& operator=(const PresidentialPardonForm&);
		virtual ~PresidentialPardonForm();
};

#endif