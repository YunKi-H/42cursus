#include "whatever.hpp"

#include <iostream>
#include <string>

int main() {
	int i = 10, j = 42;
	std::string hello("hello");
	std::string hi("hi");

	std::cout << "i: " << i << std::endl;
	std::cout << "j: " << j << std::endl;
	std::cout << "After swap" << std::endl;
	swap(i, j);
	std::cout << "a: " << i << std::endl;
	std::cout << "b: " << j << std::endl;
	std::cout << "min: " << min(i, j) << std::endl;
	std::cout << "max: " << max(i, j) << std::endl;
	std::cout << std::endl;
	std::cout << "hello: " << hello << std::endl;
	std::cout << "hi   : " << hi << std::endl;
	std::cout << "After swap" << std::endl;
	swap(hello, hi);
	std::cout << "hello: " << hello << std::endl;
	std::cout << "hi   : " << hi << std::endl;
	std::cout << "min: " << min(hello, hi) << std::endl;
	std::cout << "max: " << max(hello, hi) << std::endl;
	std::cout << std::endl;

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
