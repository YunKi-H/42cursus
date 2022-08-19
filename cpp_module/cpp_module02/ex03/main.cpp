#include <iostream>
#include "Point.hpp"

int main(void) {
	Point a(0.0, 0.0);
	Point b(0.0, 4.0);
	Point c(2.0, 0.0);
	Point p1(1.0, 1.0);
	Point p2(1.0, 2.0);
	Point p3(10.0, 10.0);

	std::cout << "Point1 is " << (bsp(a, b, c, p1) ? "inside " : "outside ")
		<< "of the triangle" << std::endl;
	std::cout << "Point2 is " << (bsp(a, b, c, p2) ? "inside " : "outside ")
		<< "of the triangle" << std::endl;
	std::cout << "Point3 is " << (bsp(a, b, c, p3) ? "inside " : "outside ")
		<< "of the triangle" << std::endl;
}
