#include <iostream>
#include "Point.hpp"

int main(void) {
	Point a(2.0, 1.0);
	Point b(1.0, 5.0);
	Point c(9.0, 1.0);
	Point p1(2.0, 2.0);
	Point p2(5.0, 3.0);
	Point p3(9.0, 6.0);

	std::cout << "6        3 " << std::endl;
	std::cout << "5b         " << std::endl;
	std::cout << "4x x       " << std::endl;
	std::cout << "3x   2     " << std::endl;
	std::cout << "2x 1   x   " << std::endl;
	std::cout << "1axxxxxxxc " << std::endl;
	std::cout << "01234567890" << std::endl;
	std::cout << "Point1 is "<< (bsp(a, b, c, p1) ? "inside " : "outside ") << "of the triangle" << std::endl;
	std::cout << "Point2 is " << (bsp(a, b, c, p2) ? "inside " : "outside ") << "of the triangle" << std::endl;
	std::cout << "Point3 is " << (bsp(a, b, c, p3) ? "inside " : "outside ") << "of the triangle" << std::endl;
}
