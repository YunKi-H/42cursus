#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int _fixed;
	static const int _fract = 8;
public:
	Fixed();
	Fixed(const int integer);
	Fixed(const float floating_point);
	Fixed(const Fixed& fixed);
	~Fixed();

	bool operator>(const Fixed &rhs);
	bool operator<(const Fixed &rhs);
	bool operator>=(const Fixed &rhs);
	bool operator<=(const Fixed &rhs);
	bool operator==(const Fixed &rhs);
	bool operator!=(const Fixed &rhs);

	Fixed operator+(const Fixed &rhs);
	Fixed operator-(const Fixed &rhs);
	Fixed operator*(const Fixed &rhs);
	Fixed operator/(const Fixed &rhs);

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	Fixed &operator=(const Fixed &rhs);

	static Fixed& min(Fixed &lhs, Fixed &rhs);
	static Fixed& max(Fixed &lhs, Fixed &rhs);
	static Fixed& min(const Fixed &lhs, const Fixed &rhs);
	static Fixed& max(const Fixed &lhs, const Fixed &rhs);

	int getRawBits() const;
	void setRawBits(int const raw);
	int toInt() const;
	float toFloat() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
