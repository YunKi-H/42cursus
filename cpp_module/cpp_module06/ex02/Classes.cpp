#include "Classed.hpp"

Base::~Base() {
}

Base *generate() {
	struct timeval	time;
	gettimeofday(&time, NULL);
	srand(time.tv_usec);
	switch (rand() % 3) {
	case 0:
		std::cout << "New A generated!" << std::endl;
		return new A();
		break;
	case 1:
		std::cout << "New B generated!" << std::endl;
		return new B();
		break;
	case 2:
		std::cout << "New C generated!" << std::endl;
		return new C();
		break;
	}
	return NULL;
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "Hmm..Maybe...A..?" << std::endl;
	} else if (dynamic_cast<B *>(p)) {
		std::cout << "Hmm..Maybe...B..?" << std::endl;
	} else if (dynamic_cast<C *>(p)) {
		std::cout << "Hmm..Maybe...C..?" << std::endl;
	} else {
		std::cout << "Hmm..Maybe...unDerived Class.." << std::endl;
	}
}

void identify(const Base &p) {
	try {
		(void)dynamic_cast<const A &>(p);
		std::cout << "This is Exactly A!" << std::endl;
		return;
	} catch(std::exception &) {
		try {
			(void)dynamic_cast<const B &>(p);
			std::cout << "This is Exactly B!" << std::endl;
			return;
		} catch(std::exception &) {
			try {
				(void)dynamic_cast<const C &>(p);
				std::cout << "This is Exactly C!" << std::endl;
				return;
			} catch(std::exception &) {
				std::cout << "This is Exactly unDerived Class!" << std::endl;
			}
		}
	}
}
