#include "Brain.hpp"

const std::string Brain::_className = "Brain";

Brain::Brain() {
	for (int i = 0; i < this->_capacity; ++i) {
		this->_ideas[i] = "Miscellaneous Thoughts";
	}
	std::cout << this->_className << " [" << this->_className << "] Constructor called!" << std::endl;
}

Brain::Brain(const Brain& brain) {
	*this = brain;
	std::cout << this->_className << " [" << this->_className << "] Constructor called!" << std::endl;
}

Brain::~Brain() {
	std::cout << this->_className << " [" << this->_className << "] Destructor called!" << std::endl;
}

Brain &Brain::operator=(const Brain &rhs) {
	for (int i = 0; i < this->_capacity; ++i) {
		this->_ideas[i] = rhs.getIdea(i);
	}
	return *this;
}

std::string Brain::getIdea(const int idx) const {
	return this->_ideas[idx];
}

int Brain::getCapacity() const {
	return this->_capacity;
}

void Brain::setIdea(const int idx, const std::string &idea) {
	this->_ideas[idx] = idea;
}
