#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <set>

int main() {
	std::vector<int> v;
	std::deque<int> d;
	std::set<int> s;

	v.push_back(1);
	v.push_back(2);
	d.push_back(1);
	d.push_back(2);
	s.insert(1);
	s.insert(2);
	for (int i = 2; i < 20; i++) {
		v.push_back(v[i - 2] + v[i - 1]);
		d.push_back(v[i - 2] + v[i - 1]);
		s.insert(v[i - 2] + v[i - 1]);
	}
	std::cout << "vector\t: ";
	for (std::vector<int>::iterator vi = v.begin(); vi != v.end() ; vi++) {
		std::cout << *vi << " ";
	}
	std::cout << std::endl;
	std::cout << "deque\t: ";
	for (std::deque<int>::iterator di = d.begin(); di != d.end() ; di++) {
		std::cout << *di << " ";
	}
	std::cout << std::endl;
	std::cout << "set\t: ";
	for (std::set<int>::iterator si = s.begin(); si != s.end() ; si++) {
		std::cout << *si << " ";
	}
	std::cout << std::endl;

	std::cout << "--vector--" << std::endl;
	std::cout << "testcase: 1 10946 987 42" << std::endl;
	try {
		std::cout << "easyfind: ";
		std::vector<int>::iterator vt;
		vt = easyfind(v, 1);
		std::cout << *vt << " ";
		vt = easyfind(v, 10946);
		std::cout << *vt << " ";
		vt = easyfind(v, 987);
		std::cout << *vt << " ";
		vt = easyfind(v, 42);
		std::cout << *vt << " ";
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--deque--" << std::endl;
	std::cout << "testcase: 1 10946 987 42" << std::endl;
	try {
		std::cout << "easyfind: ";
		std::deque<int>::iterator dt;
		dt = easyfind(d, 1);
		std::cout << *dt << " ";
		dt = easyfind(d, 10946);
		std::cout << *dt << " ";
		dt = easyfind(d, 987);
		std::cout << *dt << " ";
		dt = easyfind(d, 42);
		std::cout << *dt << " ";
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--set--" << std::endl;
	std::cout << "testcase: 1 10946 987 42" << std::endl;
	try {
		std::cout << "easyfind: ";
		std::set<int>::iterator st;
		st = easyfind(s, 1);
		std::cout << *st << " ";
		st = easyfind(s, 10946);
		std::cout << *st << " ";
		st = easyfind(s, 987);
		std::cout << *st << " ";
		st = easyfind(s, 42);
		std::cout << *st << " ";
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}
