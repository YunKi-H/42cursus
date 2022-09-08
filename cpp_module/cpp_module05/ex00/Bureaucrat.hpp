#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &bureaucrat);
	virtual ~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat *rhs);
};

#endif
