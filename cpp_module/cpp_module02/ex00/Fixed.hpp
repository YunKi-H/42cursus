#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
private:
	int _fixed;
	static const int _fract = 8;
public:
	Fixed();
	Fixed(const Fixed& fixed);
	~Fixed();
	Fixed &operator=(const Fixed& fixed);
	int getRawBits() const;
	void setRawBits(int const raw);
};



#endif
