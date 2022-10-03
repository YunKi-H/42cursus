#ifndef VECTOR_HPP
#define VERTOP_HPP

// #include <vector>
#include <iterator>

#include <memory>
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "algorithm.hpp"

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
};

} // namespace ft

#endif
