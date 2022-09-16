#ifndef CLASSES_HPP
# define CLASSES_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <sys/time.h>

class Base {
public:
	virtual ~Base();
};

class A : public Base {
};
class B : public Base {
};
class C : public Base {
};

Base *generate();
void identify(Base *p);
void identify(const Base &p);
#endif
