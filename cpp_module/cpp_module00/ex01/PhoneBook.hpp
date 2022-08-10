#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
private:
	int			_index;
	Contact		_contacts[8];
	std::string	getInput(std::string msg);
	void		printInStyle(std::string str);
	void		printContact(int index);
	std::string	toUpper(std::string str);
public:
	std::string	getCommand();
	void		add();
	void		search();
	PhoneBook();
	~PhoneBook();
};

#endif
