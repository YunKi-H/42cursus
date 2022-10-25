#ifndef MAP_HPP
#define MAP_HPP

#include <map>
#include <iterator>

#include <memory>
#include <stdexcept>
#include "pair.hpp"
#include "reverse_iterator.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"

namespace ft {

enum _nodeColor {
	RED = false,
	BLACK = true
};

template <typename T>
struct _mapNode {
	typedef _mapNode* _nodePtr;
	typedef T _valueType;

	_valueType _value;
	bool _color;
	_nodePtr _parent;
	_nodePtr _left;
	_nodePtr _right;

	_mapNode() : _value(NULL), _color(RED), _parent(NULL), _left(NULL), _right(NULL) {}
	_mapNode(const _valueType &value) : _value(value), _color(RED), _parent(NULL), _left(NULL), _right(NULL) {}
	_mapNode(const _mapNode &other) : _value(other._value), _color(other._color), _parent(other._parent), _left(other._left), _right(other._right) {}
	virtual ~_mapNode() {}

	_mapNode& operator=(const _mapNode &rhs) {
		this->_value = rhs._value;
		this->_color = rhs._color;
		this->_parent = rhs._parent;
		this->_left = rhs._left;
		this->_right = rhs._right;
		return *this;
	}
};

template <class T>
class map_iterator {
public:
	typedef T iterator_type;
	typedef typename std::bidirectional_iterator_tag iterator_category;
	typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
	typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
	typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
	typedef typename ft::iterator_traits<iterator_type>::reference reference;

protected:
	pointer current;

public:
	map_iterator() : current() {}
	explicit map_iterator(iterator_type it) : current(it) {}
	template <class Iter>
	map_iterator(const map_iterator<Iter> & it) : current(it.base()) {}
	virtual ~map_iterator() {}
};

template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
class map {
public:
	typedef Key key_type;
	typedef T mapped_type;
	typedef ft::pair<const key_type, mapped_type> value_type;
	typedef Compare key_compare;
	typedef Allocator allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef typename allocator_type::size_type size_type;
	typedef typename allocator_type::difference_type difference_type;

	typedef ft::reverse_iterator<mapped_type> iterator;
	typedef ft::reverse_iterator<mapped_type> const_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	template <class Key, class T, class Compare, class Alloc>
	class ft::map<Key,T,Compare,Alloc>::value_compare
	: std::binary_function<value_type,value_type,bool> {
		friend class map;
	protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator() (const value_type& x, const value_type& y) const{
			return comp(x.first, y.first);
		}
	}
protected:

public:
	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	map (const map& x);
	~map();

	map& operator=(const map& x);

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	bool empty() const;
	size_type size() const;
	size_type max_size() const;

	mapped_type& operator[] (const key_type& k);

	ft::pair<iterator,bool> insert (const value_type& val);
	iterator insert (iterator position, const value_type& val);
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last);

	void erase (iterator position);
	size_type erase (const key_type& k);
	void erase (iterator first, iterator last);
	void swap (map& x);
	void clear();

	key_compare key_comp() const;
	value_compare value_comp() const;

	iterator find (const key_type& k);
	const_iterator find (const key_type& k) const;
	size_type count (const key_type& k) const;
	iterator lower_bound (const key_type& k);
	const_iterator lower_bound (const key_type& k) const;
	iterator upper_bound (const key_type& k);
	const_iterator upper_bound (const key_type& k) const;
	ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
	ft::pair<iterator,iterator> equal_range (const key_type& k);

	allocator_type get_allocator() const;

};

template <class Key, class T, class Compare, class Alloc>
bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
}
template <class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
}
template <class Key, class T, class Compare, class Alloc>
bool operator< (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
}
template <class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
}
template <class Key, class T, class Compare, class Alloc>
bool operator> (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
}
template <class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
}

template <class Key, class T, class Compare, class Alloc>
void swap (map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) {
}

} // namespace ft

#endif
