#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
private:
	int			_index;
	Contact		_contacts[8];
	std::string	getInput(std::string msg);
public:
	void		addContact();
	std::string	getCommand();
	PhoneBook();
	~PhoneBook();
};

#endif
