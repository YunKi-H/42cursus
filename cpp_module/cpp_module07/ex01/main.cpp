#include "iter.hpp"

void squareInt(int &i) {
	i *= i;
}

int main() {
	int arrInt[7] = {1, 1, 2, 3, 5, 8, 13};
	std::string arrString[5] = {
		"apple",
		"orange",
		"banana",
		"melon",
		"strawberry"
	};

	iter(arrInt, 7, print);
	std::cout << std::endl;
	iter(arrString, 5, print);
	std::cout << std::endl;
	iter(arrInt, 7, squareInt);
	iter(arrInt, 7, print);
	std::cout << std::endl;
}
