#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array {
private:
	std::size_t _size;
	T *_elem;
public:
	Array() : _size(0), _elem(NULL) {}
	Array(unsigned int n) : _size(n), _elem(NULL) {
		if (_size != 0) {
			_elem = new T[_size];
		}
	}
	Array(const Array &array) {
		this->_size = array._size;
		if (this->_size != 0) {
			this->_elem = new T[this->_size];
			for (std::size_t i = 0; i < this->_size; i++) {
				this->_elem[i] = array._elem[i];
			}
		}
	}
	virtual ~Array() {
		delete[] this->_elem;
	}

	Array &operator=(const Array &rhs) {
		this->_size = rhs._size;
		if (this->_size != 0) {
			if (this->_elem != NULL) {
				delete[] this->_elem;
			}
			this->_elem = new T[this->_size];
			for (std::size_t i = 0; i < this->_size; i++) {
				this->_elem[i] = rhs._elem[i];
			}
		}
	}
	T &operator[](std::size_t index) {
		if (index < 0 || index > this->_size - 1) {
			throw OutOfRangeException();
		}
		return this->_elem[index];
	}

	class OutOfRangeException : public std::exception {
		const char *what() const throw() {
			return "Out Of Range!";
		}
	};
};


#endif
