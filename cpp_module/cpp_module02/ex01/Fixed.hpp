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
	Fixed &operator=(const Fixed &rhs);
	int getRawBits() const;
	void setRawBits(int const raw);
	int toInt() const;
	float toFloat() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
