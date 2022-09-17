#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &haystack, const int needle) {
	typename T::iterator iter = std::find(haystack.begin(), haystack.end(), needle);
	if (iter == haystack.end()) {
		throw std::runtime_error("No element in here!");
	}
	return iter;
}

template <typename T>
const typename T::iterator easyfind(const T &haystack, const int needle) {
	typename T::iterator iter = std::find(haystack.begin(), haystack.end(), needle);
	if (iter == haystack.end()) {
		throw std::runtime_error("No element in here!");
	}
	return iter;
}

#endif
