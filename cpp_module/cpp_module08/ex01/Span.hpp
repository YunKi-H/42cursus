#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <cstdlib>
#include <sys/time.h>

class Span {
private:
	std::vector<int> _vec;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &span);
	virtual ~Span();

	Span &operator=(const Span &rhs);

	void addNumber(const unsigned int &nbr);
	void addRandomNumbers(const unsigned int &amount, const unsigned int &limits);
	unsigned int shortestSpan() const ;
	unsigned int longestSpan() const ;
	void printSpan() const;
};

#endif
