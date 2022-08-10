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
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickName() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSceret() const;
	void setContact(
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
