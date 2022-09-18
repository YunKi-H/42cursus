#include "Span.hpp"
#include <iostream>

int main() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try {
		std::cout << "test Full" << std::endl;
		Span full(3);
		full.addNumber(0);
		full.printSpan();
		full.addNumber(1);
		full.printSpan();
		full.addNumber(2);
		full.printSpan();
		full.addNumber(3);
		full.printSpan();
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "test Empty" << std::endl;
		Span empty(3);
		empty.shortestSpan();
		empty.printSpan();
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Span test(10000);
	test.addRandomNumbers(10, 100000000);
	test.printSpan();
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;
	return 0;
}
