#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
	static const std::string _className;
	static const int _capacity = 100;
	std::string _ideas[_capacity];
public:
	Brain();
	Brain(const Brain& brain);
	virtual ~Brain();

	Brain &operator=(const Brain &rhs);

	std::string getIdea(const int idx) const;
	int getCapacity() const;
	void setIdea(const int idx, const std::string &idea);
};



#endif
