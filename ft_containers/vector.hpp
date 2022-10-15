#ifndef VECTOR_HPP
#define VECTOR_HPP

// #include <vector>
#include <iterator>

#include <memory>
#include <stdexcept>
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"

namespace ft {

template <class T, class Alloc = std::allocator<T> >
class vector {
public:
	typedef T value_type;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::size_type size_type;
	typedef typename allocator_type::difference_type difference_type;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef typename ft::random_access_iterator<value_type> iterator;
	typedef typename ft::random_access_iterator<const value_type> const_iterator;
	typedef typename ft::reverse_iterator<iterator> reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

protected:
	pointer _begin;
	pointer _end;
	pointer _capacity;
	allocator_type _alloc;

public:
	explicit vector(const allocator_type& alloc = allocator_type())
	: _begin(NULL), _end(NULL), _capacity(NULL), _alloc(alloc) {}
	explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	: _begin(NULL), _end(NULL), _capacity(NULL), _alloc(alloc) {
		if (n > this->max_size()) {
			throw std::length_error("vector");
		}
		this->_begin = this->_alloc.allocate(n);
		this->_end = this->_begin + n;
		this->_capacity = this->_end;
		for (pointer i = this->_begin; i < this->_end; i++) {
			this->_alloc.construct(i, val);
		}
	}
	template <class InputIterator>
	vector(InputIterator first, InputIterator last, const allocator_type alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
	: _begin(NULL), _end(NULL), _capacity(NULL), _alloc(alloc) {
		this->assign(first, last);
	}
	vector(const vector& x)
	: _begin(NULL), _end(NULL), _capacity(NULL), _alloc(x._alloc) {
		*this = x;
	}
	virtual ~vector() {
		if (this->_begin) {
			size_type n = this->capacity();
			this->clear();
			this->_alloc.deallocate(this->_begin, n);
			this->_begin = NULL;
			this->_end = NULL;
			this->_capacity = NULL;
		}
	}

	vector& operator=(const vector& x) {
		if (this != &x) {
			this->assign(x.begin(), x.end());
		}
		return *this;
	}
	iterator begin() {
		return iterator(this->_begin);
	}
	const_iterator begin() const {
		return const_iterator(this->_begin);
	}
	iterator end() {
		return iterator(this->_end);
	}
	const_iterator end() const {
		return const_iterator(this->_end);
	}
	reverse_iterator rbegin() {
		return reverse_iterator(this->end());
	}
	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(this->end());
	}
	reverse_iterator rend() {
		return reverse_iterator(this->begin());
	}
	const_reverse_iterator rend() const {
		return const_reverse_iterator(this->begin());
	}

	size_type size() const {
		return this->_end - this->_begin;
	}
	size_type max_size() const {
		return std::min<size_type>(std::numeric_limits<size_type>::max(), this->_alloc.max_size());
	}
	void resize (size_type n, value_type val = value_type()) {
		if (this->size() < n) {
			if (this->capacity() < n) {
				this->reserve(n);
			}
			while (this->size() != n) {
				this->_alloc.construct(this->_end, val);
				this->_end++;
			}
		} else if (this->size() > n) {
			while (this->size() != n) {
				this->_end--;
				this->_alloc.destroy(this->_end);
			}
		}
	}
	size_type capacity() const {
		return this->_capacity - this->_begin;
	}
	bool empty() const {
		return this->_begin == this->_end;
	}
	void reserve (size_type n) {
		if (this->capacity() >= n) {
			return;
		}
		n = n > this->capacity() * 2 ? n : this->capacity() * 2;
		size_type oldSize = this->size();
		pointer newBegin = this->_alloc.allocate(n);
		std::uninitialized_copy(this->_begin, this->_end, newBegin);
		this->clear();
		this->_alloc.deallocate(this->_begin, this->capacity());
		this->_begin = newBegin;
		this->_end = this->_begin + oldSize;
		this->_capacity = this->_begin + n;
	}

	reference operator[] (size_type n) {
		return this->_begin[n];
	}
	const_reference operator[] (size_type n) const {
		return this->_begin[n];
	}
	reference at (size_type n) {
		if (n > this->size()) {
			throw std::out_of_range("vector");
		}
		return this->_begin[n];
	}
	const_reference at (size_type n) const {
		if (n > this->size()) {
			throw std::out_of_range("vector");
		}
		return this->_begin[n];
	}
	reference front() {
		return this->_begin[0];
	}
	const_reference front() const {
		return this->_begin[0];
	}
	reference back() {
		return *(this->_end - 1);
	}
	const_reference back() const {
		return *(this->_end - 1);
	}

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) {
		size_type dist = std::distance(first, last);
		this->clear();
		if (this->capacity() < dist) {
			this->reserve(dist);
		}
		std::uninitialized_copy(first, last, this->_begin);
		this->_end = this->_begin + dist;
	}
	void assign (size_type n, const value_type& val) {
		this->clear();
		if (this->capacity() < n) {
			this->reserve(n);
		}
		std::uninitialized_fill_n(this->_begin, n, val);
		this->_end = this->_begin + n;
	}
	void push_back (const value_type& val) {
		if (this->capacity() < this->size() + 1) {
			this->reserve(this->size() + 1);
		}
		this->_alloc.construct(this->_end, val);
		this->_end++;
	}
	void pop_back() {
		this->_end--;
		this->_alloc.destroy(this->_end);
	}
	iterator insert (iterator position, const value_type& val) {
		difference_type diff = position - this->begin();
		if (this->capacity() < this->size() + 1) {
			this->reserve(this->size() + 1);
		}
		pointer p = this->_begin + diff;
		this->_alloc.construct(this->_end, val);
		this->_end++;
		std::copy_backward(p, this->_end - 1, this->_end);
		*p = val;
		return iterator(p);
	}
	void insert (iterator position, size_type n, const value_type& val) {
		difference_type diff = position - this->begin();
		this->resize(this->size() + n, 0);
		pointer p = this->_begin + diff;
		std::copy_backward(p, this->_end - n, this->_end);
		while (n--) {
			*p++ = val;
		}
	}
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) {
		difference_type diff = position - this->begin();
		difference_type n = std::distance(first, last);
		this->resize(this->size() + n);
		pointer p = this->_begin + diff;
		std::copy_backward(p, this->_end - n, this->_end);
		for (InputIterator tmp = first; tmp != last; ++tmp) {
			*p++ = *tmp;
		}
	}
	iterator erase (iterator position) {
		if (this->empty()) {
			return position;
		}
		std::copy(position + 1, this->end(), position);
		this->_end--;
		this->_alloc.destroy(this->_end);
		return position;
	}
	iterator erase (iterator first, iterator last) {
		difference_type diff = std::distance(first, last);
		std::copy(last, this->end(), first);
		while (diff--) {
			this->_end--;
			this->_alloc.destroy(this->_end);
		}
		return first;
	}
	void swap (vector& x) {
		pointer tmpBegin = this->_begin;
		pointer tmpEnd = this->_end;
		pointer tmpCapacity = this->_capacity;
		this->_begin = x._begin;
		this->_end = x._end;
		this->_capacity = x._capacity;
		x._begin = tmpBegin;
		x._end = tmpEnd;
		x._capacity = tmpCapacity;
	}
	void clear() {
		while (this->_end != this->_begin) {
			this->_end--;
			this->_alloc.destroy(this->_end);
		}
	}

	allocator_type get_allocator() const {
		return this->_alloc;
	}

};

template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}
template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return !(lhs == rhs);
}
template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return !(rhs < lhs);
}
template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return rhs < lhs;
}
template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return !(lhs < rhs);
}
template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
	x.swap(y);
}

} // namespace ft

#endif
