#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_fixed = 0;
}

Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = integer << _fract;
}

Fixed::Fixed(const float floating_point) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(floating_point * (1 << _fract));
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
}

int Fixed::toInt() const {
	return this->_fixed >> _fract;
}

float Fixed::toFloat() const {
	return (float)this->_fixed / (1 << _fract);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
