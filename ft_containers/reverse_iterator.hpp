#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

template <class Iterator>
class reverse_iterator {
protected:
	Iterator current;

public:
	typedef Iterator iterator_type;
	typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
	typedef typename ft::iterator_traits<Iterator>::value_type value_type;
	typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
	typedef typename ft::iterator_traits<Iterator>::pointer pointer;
	typedef typename ft::iterator_traits<Iterator>::reference reference;

	reverse_iterator() : current() {}
	explicit reverse_iterator(iterator_type it) : current(it) {}
	template <class Iter>
	reverse_iterator(const reverse_iterator<Iter> &rev_it) : current(rev_it.base()) {}
	virtual ~reverse_iterator() {}

	iterator_type base() const {
		return current;
	}

	reference operator*() const {
		Iterator temp = current;
		return *--temp;
	}
	reverse_iterator operator+(difference_type n) const {
		return reverse_iterator(current - n);
	}
	reverse_iterator& operator++() {
		--current;
		return *this;
	}
	reverse_iterator operator++(int) {
		reverse_iterator temp = *this;
		++(*this);
		return temp;
	}
	reverse_iterator& operator+=(difference_type n) {
		current -= n;
		return *this;
	}
	reverse_iterator operator-(difference_type n) const {
		return reverse_iterator(current + n);
	}
	reverse_iterator& operator--() {
		++current;
		return *this;
	}
	reverse_iterator operator--(int) {
		reverse_iterator temp = *this;
		--(*this);
		return temp;
	}
	reverse_iterator& operator-=(difference_type n) {
		current += n;
		return *this;
	}
	pointer operator->() const {
		return &operator*();
	}
	reference operator[](difference_type n) const {
		return *(*this + n);
	}
};

template <class Iterator1, class Iterator2>
bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() == rhs.base();
}
template <class Iterator1, class Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() != rhs.base();
}
template <class Iterator1, class Iterator2>
bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() > rhs.base();
}
template <class Iterator1, class Iterator2>
bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() >= rhs.base();
}
template <class Iterator1, class Iterator2>
bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() < rhs.base();
}
template <class Iterator1, class Iterator2>
bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return lhs.base() <= rhs.base();
}

template <class Iterator>
reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
	return reverse_iterator<Iterator>(rev_it.base() - n);
}
template <class Iterator1, class Iterator2>
typename reverse_iterator<Iterator1>::difference_type operator- (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
	return rhs.base() - lhs.base();
}

} // namespace ft

#endif
