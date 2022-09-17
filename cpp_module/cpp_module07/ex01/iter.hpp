#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T *address, std::size_t len, void (*func)(T &)) {
	for (std::size_t i = 0; i < len; i++) {
		func(address[i]);
	}
}

template <typename T>
void print(T &arg) {
	std::cout << arg << " ";
}

#endif
