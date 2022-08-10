#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
private:
	int			_index;
	Contact		_contacts[8];
	std::string	_getInput(std::string msg);
	void		_printInStyle(std::string str);
	void		_printContact(int index) const;
	std::string	_toUpper(std::string str);
public:
	std::string	getCommand();
	void		add();
	void		search();
	PhoneBook();
	~PhoneBook();
};

#endif
