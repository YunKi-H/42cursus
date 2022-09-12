#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sys/time.h>
#include "Form.hpp"

class RobotomyRequestForm : public Form {
private:
	static const std::string _className;
	static const int _signGrade = 72;
	static const int _excuteGrade = 45;

	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

	virtual void execute(const Bureaucrat &excutor) const;
};

#endif
