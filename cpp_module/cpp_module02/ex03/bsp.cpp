#include "Point.hpp"

typedef Point Vec;

Vec operator-(const Point &lhs, const Point &rhs) {
	return Point(
		lhs.getX().toFloat() - rhs.getX().toFloat(),
		lhs.getY().toFloat() - rhs.getY().toFloat()
	);
}

Fixed operator*(const Vec &lhs, const Vec &rhs) {
	return Fixed(
		lhs.getX().toFloat() * rhs.getY().toFloat() -
		lhs.getY().toFloat() * rhs.getX().toFloat()
	);
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
	return (
		(a - b) * (a - point) < Fixed(0) &&
		(b - c) * (b - point) < Fixed(0) &&
		(c - a) * (c - point) < Fixed(0)
	);
}
