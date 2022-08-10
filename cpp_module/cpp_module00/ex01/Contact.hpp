#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
public:
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickName();
	std::string	getPhoneNumber();
	std::string	getDarkestSceret();
	Contact(
		std::string	firstName,
		std::string	lastName,
		std::string	nickName,
		std::string	phoneNumber,
		std::string	darkestSecret
	);
	Contact();
	~Contact();
};

#endif
