#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat {
private:
	static const int _gradeHighest = 1;
	static const int _gradeLowest = 150;

	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, const int &grade);
	Bureaucrat(const Bureaucrat &bureaucrat);
	virtual ~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &rhs);

	const std::string &getName() const;
	const int &getGrade() const;
	void increGrade();
	void decreGrade();

	class GradeTooHighException : public std::exception {
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
