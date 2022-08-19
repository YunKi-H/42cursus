#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	const Fixed _x;
	const Fixed _y;
public:
	Point();
	Point(const Point& point);
	Point(const float x, const float y);
	~Point();

	Point &operator=(const Point &rhs);

	const Fixed getX() const;
	const Fixed getY() const;
};

bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif
