#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

template <class T>
class random_access_iterator {

public:
	typedef T* iterator_type;
	typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
	typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
	typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
	typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
	typedef typename ft::iterator_traits<iterator_type>::reference reference;

protected:
	pointer current;

public:
	random_access_iterator() : current() {}
	explicit random_access_iterator(iterator_type it) : current(it) {}
	template <class Iter>
	random_access_iterator(const random_access_iterator<Iter> &it) : current(it.base()) {}
	virtual ~random_access_iterator() {}

	iterator_type base() const {
		return current;
	}

	reference operator*() const {
		return *current;
	}
	random_access_iterator operator+(difference_type n) const {
		return random_access_iterator(current + n);
	}
	random_access_iterator& operator++() {
		++current;
		return *this;
	}
	random_access_iterator operator++(int) {
		random_access_iterator temp = *this;
		++(*this);
		return temp;
	}
	random_access_iterator& operator+=(difference_type n) {
		current += n;
		return *this;
	}
	random_access_iterator operator-(difference_type n) const {
		return random_access_iterator(current - n);
	}
	random_access_iterator& operator--() {
		--current;
		return *this;
	}
	random_access_iterator operator--(int) {
		random_access_iterator temp = *this;
		--(*this);
		return temp;
	}
	random_access_iterator& operator-=(difference_type n) {
		current -= n;
		return *this;
	}
	pointer operator->() const {
		return &operator*();
	}
	reference operator[](difference_type n) const {
		return *(*this + n);
	}
};

template <class Iterator>
bool operator==(const random_access_iterator<Iterator>& lhs, const random_access_iterator<Iterator>& rhs) {
	return lhs.base() == rhs.base();
}
template <class Iterator>
bool operator!=(const random_access_iterator<Iterator>& lhs, const random_access_iterator<Iterator>& rhs) {
	return lhs.base() != rhs.base();
}
template <class Iterator>
bool operator<(const random_access_iterator<Iterator>& lhs, const random_access_iterator<Iterator>& rhs) {
	return lhs.base() < rhs.base();
}
template <class Iterator>
bool operator<=(const random_access_iterator<Iterator>& lhs, const random_access_iterator<Iterator>& rhs) {
	return lhs.base() <= rhs.base();
}
template <class Iterator>
bool operator>(const random_access_iterator<Iterator>& lhs, const random_access_iterator<Iterator>& rhs) {
	return lhs.base() > rhs.base();
}
template <class Iterator>
bool operator>=(const random_access_iterator<Iterator>& lhs, const random_access_iterator<Iterator>& rhs) {
	return lhs.base() >= rhs.base();
}

template <class Iterator>
random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n, const random_access_iterator<Iterator>& it) {
	return random_access_iterator<Iterator>(it.base() + n);
}
template <class Iterator>
typename random_access_iterator<Iterator>::difference_type operator-(const random_access_iterator<Iterator>& lhs, const random_access_iterator<Iterator>& rhs) {
	return lhs.base() - rhs.base();
}

} // namespace ft

#endif
