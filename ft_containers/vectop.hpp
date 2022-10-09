#ifndef VECTOR_HPP
#define VERTOP_HPP

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
		for (pointer i = this->_begin; i < end; i++) {
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
		if (this->_begin == NULL) {
			return;
		}
		for (pointer i = this->_begin; i < this->_end; i++) {
			this->_alloc.destroy(i);
		}
		this->_alloc.deallocate(this->_begin, this->capacity());
		this->_begin = this->_end = this->_capacity = NULL;
	}

	vector& operator=(const vector& x);
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
	void resize (size_type n, value_type val = value_type());
	size_type capacity() const {
		return this->_capacity - this->_begin;
	}
	bool empty() const {
		return this->_begin == this->_end;
	}
	void reserve (size_type n);

	reference operator[] (size_type n);
	const_reference operator[] (size_type n) const;
	reference at (size_type n);
	const_reference at (size_type n) const;
	reference front();
	const_reference front() const;
	reference back();
	const_reference back() const;

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last);
	void assign (size_type n, const value_type& val);
	void push_back (const value_type& val);
	void pop_back();
	iterator insert (iterator position, const value_type& val);
	void insert (iterator position, size_type n, const value_type& val);
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last);
	iterator erase (iterator position);
	iterator erase (iterator first, iterator last);
	void swap (vector& x);
	void clear();

	allocator_type get_allocator() const;

};

template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);


} // namespace ft

#endif
