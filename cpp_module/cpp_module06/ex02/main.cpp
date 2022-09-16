#include "Classed.hpp"

int main() {
	Base *whoAmI = generate();

	identify(whoAmI);
	identify(*whoAmI);
}
