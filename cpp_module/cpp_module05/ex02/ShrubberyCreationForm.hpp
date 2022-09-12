#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form {
private:
	static const std::string _className;
	static const int _signGrade = 145;
	static const int _excuteGrade = 137;
	static const std::string _tree;

	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

	virtual void execute(const Bureaucrat &excutor) const;
};

#endif
