#include "Fixed.hpp"

Fixed::Fixed() {
	// std::cout << "Default constructor called" << std::endl;
	this->_fixed = 0;
}

Fixed::Fixed(const int integer) {
	// std::cout << "Int constructor called" << std::endl;
	this->_fixed = integer << _fract;
}

Fixed::Fixed(const float floating_point) {
	// std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(floating_point * (1 << _fract));
}

Fixed::Fixed(const Fixed& fixed) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator>(const Fixed &rhs) {
	return this->_fixed > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) {
	return this->_fixed < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) {
	return this->_fixed >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) {
	return this->_fixed <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) {
	return this->_fixed == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) {
	return this->_fixed != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed &rhs) {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++() {
	this->_fixed++;
	return *this;
}

Fixed& Fixed::operator--() {
	this->_fixed--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed before = *this;
	this->_fixed++;
	return before;
}

Fixed Fixed::operator--(int) {
	Fixed before = *this;
	this->_fixed--;
	return before;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = rhs.getRawBits();
	return *this;
}

Fixed& Fixed::min(Fixed &lhs, Fixed &rhs) {
	return lhs.getRawBits() < rhs.getRawBits() ? lhs : rhs;
}

Fixed& Fixed::max(Fixed &lhs, Fixed &rhs) {
	return lhs.getRawBits() > rhs.getRawBits() ? lhs : rhs;
}

Fixed& Fixed::min(const Fixed &lhs, const Fixed &rhs) {
	return lhs.getRawBits() < rhs.getRawBits() ? const_cast<Fixed&>(lhs) : const_cast<Fixed&>(rhs);
}

Fixed& Fixed::max(const Fixed &lhs, const Fixed &rhs) {
	return lhs.getRawBits() > rhs.getRawBits() ? const_cast<Fixed&>(lhs) : const_cast<Fixed&>(rhs);
}


int Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
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
