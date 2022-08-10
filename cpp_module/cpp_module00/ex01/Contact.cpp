#include <iostream>
#include <iomanip>
#include "Contact.hpp"

std::string Contact::getFirstName() const {
	return (this->_firstName);
}

std::string Contact::getLastName() const {
	return (this->_lastName);
}

std::string Contact::getNickName() const {
	return (this->_nickName);
}

std::string Contact::getPhoneNumber() const {
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSceret() const {
	return (this->_darkestSecret);
}

void Contact::setContact(
	std::string	firstName,
	std::string	lastName,
	std::string	nickName,
	std::string	phoneNumber,
	std::string	darkestSecret
) {
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickName = nickName;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

Contact::Contact() {
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

Contact::~Contact() {
}
