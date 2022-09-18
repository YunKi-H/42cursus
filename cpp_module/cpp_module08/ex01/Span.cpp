#include "Span.hpp"

Span::Span() {
}

Span::Span(unsigned int N) {
	this->_vec.reserve(N);
}

Span::Span(const Span &span) {
	*this = span;
}

Span::~Span() {
}

Span &Span::operator=(const Span &rhs) {
	this->_vec = rhs._vec;
	return *this;
}

void Span::addNumber(const unsigned int &nbr) {
	if (this->_vec.size() == this->_vec.capacity()) {
		throw std::runtime_error("No more Space");
	}
	this->_vec.push_back(nbr);
}

void Span::addRandomNumbers(const unsigned int &amount, const unsigned int &limits) {
	struct timeval	time;
	gettimeofday(&time, NULL);
	srand(time.tv_usec);
	for (unsigned int i = 0; i < amount; i++) {
		this->_vec.push_back(rand() % limits);
	}
}

unsigned int Span::shortestSpan() const  {
	if (this->_vec.size() < 2) {
		throw std::runtime_error("Need more Elements");
	}
	std::vector<int> tmp = this->_vec;
	std::sort(tmp.begin(), tmp.end());
	unsigned int span = UINT_MAX;
	for (std::vector<int>::const_iterator it = tmp.begin() + 1; it != tmp.end(); it++) {
		if (static_cast<unsigned int>(*it - *(it - 1)) < span) {
			span = static_cast<unsigned int>(*it - *(it - 1));
		}
	}
	return span;
}

unsigned int Span::longestSpan() const  {
	if (this->_vec.size() < 2) {
		throw std::runtime_error("Need more Elements");
	}
	return *std::max_element(this->_vec.begin(), this->_vec.end())
		 - *std::min_element(this->_vec.begin(), this->_vec.end());
}

void Span::printSpan() const {
	for (std::vector<int>::const_iterator it = this->_vec.begin(); it != this->_vec.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	// std::cout << "max_elem : " << *std::max_element(this->_vec.begin(), this->_vec.end()) << std::endl;
	// std::cout << "min_elem : " << *std::min_element(this->_vec.begin(), this->_vec.end()) << std::endl;
}
