#include "whatever.hpp"

#include <iostream>
#include <string>

int main() {
	int a = 10, b = 42;
	std::string hello("hello");
	std::string hi("hi");

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "After swap" << std::endl;
	swap(a, b);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "min: " << min(a, b) << std::endl;
	std::cout << "max: " << max(a, b) << std::endl;
	std::cout << std::endl;
	std::cout << "hello: " << hello << std::endl;
	std::cout << "hi   : " << hi << std::endl;
	std::cout << "After swap" << std::endl;
	swap(hello, hi);
	std::cout << "hello: " << hello << std::endl;
	std::cout << "hi   : " << hi << std::endl;
	std::cout << "min: " << min(hello, hi) << std::endl;
	std::cout << "max: " << max(hello, hi) << std::endl;
}
