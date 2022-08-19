#include "Point.hpp"

Point::Point() {
}

Point::Point(const Point& point) {
	*this = point;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::~Point() {
}


Point& Point::operator=(const Point &rhs) {
	const_cast<Fixed&>(this->_x) = rhs.getX();
	const_cast<Fixed&>(this->_y) = rhs.getY();
	return *this;
}

const Fixed Point::getX() const {
	return this->_x;
}

const Fixed Point::getY() const {
	return this->_y;
}
