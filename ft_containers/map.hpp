#ifndef MAP_HPP
#define MAP_HPP

// #include <map>
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

	static _nodePtr _minimum(_nodePtr x) {
		while (x->_left != NULL) {
			x = x->_left;
		}
		return x;
	}
	static _nodePtr _maximum(_nodePtr x) {
		while (x->_right != NULL) {
			x = x->_right;
		}
		return x;
	}

	static _nodePtr _nextNode(_nodePtr x) {
		if (x->_right != NULL) {
			x = x->_right;
			x = x->_minimum();
		} else {
			_nodePtr y = x->_parent;
			while (x == y->_right) {
				x = y;
				y = x->_parent;
			}
			x = y;
		}
		return x;
	}
	static _nodePtr _prevNode(_nodePtr x) {
		if (x->_left != NULL) {
			x = x->_left;
			x = x->_maximum;
		} else {
			_nodePtr y = x->_parent;
			while (x == y->_left) {
				x = y;
				y = x->_parent;
			}
			x = y;
		}
		return x;
	}
};

template <class T>
class map_iterator {
public:
	typedef T iterator_type;
	typedef typename std::bidirectional_iterator_tag iterator_category;
	typedef typename ft::iterator_traits<ft::_mapNode<iterator_type> *>::value_type value_type;
	typedef typename ft::iterator_traits<ft::_mapNode<iterator_type> *>::difference_type difference_type;
	typedef typename ft::iterator_traits<ft::_mapNode<iterator_type> *>::pointer pointer;
	typedef typename ft::iterator_traits<ft::_mapNode<iterator_type> *>::reference reference;

protected:
	pointer _node;

public:
	map_iterator() : _node() {}
	explicit map_iterator(iterator_type it) : _node(it) {}
	template <class Iter>
	map_iterator(const map_iterator<Iter> & it) : _node(it._node) {}
	virtual ~map_iterator() {}

	friend bool operator==(const map_iterator& lhs, const map_iterator& rhs) {
		return lhs._node == rhs._node;
	}
	friend bool operator!=(const map_iterator& lhs, const map_iterator& rhs) {
		return lhs._node != rhs._node;
	}
	reference operator*() const {
		return *(&static_cast<_mapNode<T> >(_node)._value);
	}
	pointer operator->() const {
		return &static_cast<_mapNode<T> >(_node)._value;
	}
	map_iterator& operator++() {
		this->_node = this->_node._nextNode();
		return *this;
	}
	map_iterator operator++(int) {
		map_iterator temp(*this);
		++(*this);
		return temp;
	}
	map_iterator& operator--() {
		this->_node = this->_node._prevNode();
		return *this;
	}
	map_iterator operator--(int) {
		map_iterator temp(*this);
		--(*this);
		return temp;
	}
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

	typedef ft::map_iterator<value_type> iterator;
	typedef ft::map_iterator<const value_type> const_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	class value_compare
	: public std::binary_function<value_type,value_type,bool> {
		friend class map<Key, T, Compare, Allocator>;
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
	};

protected:
	typedef _mapNode<value_type> _node_type;
	typedef _mapNode<value_type>* _node_pointer;
	typedef typename allocator_type::template rebind<_node_type>::other _node_allocator;

	_node_pointer _begin;
	_node_pointer _end;
	_node_allocator _alloc;
	key_compare _key_compare;
	value_compare _value_compare;
	size_type _size;

	void _destructTree(_node_pointer node) {
		if (node == NULL) {
			return;
		}
		_destructTree(node->_left);
		_destructTree(node->_right);
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}

	bool _isRoot(_node_pointer node) {
		return node->_parent == this->_end;
	}

	void _reColoring(_node_pointer node) {

	}
	void _reStructuring(_node_pointer node) {

	}

	void _rotateRight(_node_pointer node) {
		_node_pointer y = node->_right;
		if (y->_left != NULL) {
			y->_left->_parent = node;
			node->_right = y->_left;
			y->_left = NULL;
		}
		if (this->_isRoot(node)) {
			this->_end->_left = y;
			y->_parent = this->_end;
			node->_parent = NULL
		} else if (node->_parent->_left == node) {
			node->_parent->_left = y;
			y->_parent = node->_parent;
		} else {
			node->_parent->_right = y;
			y->_parent = node->_parent;
		}
		node->_parent = y;
		y->_left = node;
	}
	void _rotateLeft(_node_pointer node) {
		_node_pointer y = node->_left;
		if (y->_right != NULL) {
			y->_right->_parent = node;
			node->_left = y->_right;
			y->_right = NULL;
		}
		if (this->_isRoot(node)) {
			this->_end->_right = y;
			y->_parent = this->_end;
			node->_parent = NULL
		} else if (node->_parent->_right == node) {
			node->_parent->_right = y;
			y->_parent = node->_parent;
		} else {
			node->_parent->_left = y;
			y->_parent = node->_parent;
		}
		node->_parent = y;
		y->_right = node;
	}

	_node_pointer _searchPosition(const value_type& value) {
		_node_pointer node = this->_end->_left;
		_node_pointer tmp = this->_end;
		while (node != NULL) {
			tmp = node;
			if (_value_compare(value, node->_value)) {
				node = node->_left;
			} else if (_value_compare(node->_value, value)) {
				node = node->_right;
			} else {
				return node;
			}
		}
		return tmp;
	}

public:
	explicit map (
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
		: _alloc(alloc),
		_key_compare(comp),
		_value_compare(comp),
		_size(size_type()) {
			this->_end = this->_alloc.allocate(1);
			this->_alloc.construct(this->_end, value_type());
			this->_end->_color = BLACK;
			this->_begin = this->_end;
	}
	template <class InputIterator>
	map (
		InputIterator first,
		InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		: _alloc(alloc),
		_key_compare(comp),
		_value_compare(comp),
		_size(size_type()) {
			this->_end = this->_alloc.allocate(1);
			this->_alloc.construct(this->_end, value_type());
			this->_end->_color = BLACK;
			this->_begin = this->_end;
			this->insert(first, last);
	}
	map (const map& x)
	: _alloc(x._alloc),
	_key_compare(x._key_compare),
	_value_compare(x._value_compare),
	_size(size_type()) {
		this->_end = this->_alloc.allocate(1);
		this->_alloc.construct(this->_end, value_type());
		this->_end->_color = BLACK;
		this->_begin = this->_end;
		this->insert(x.begin(), x.end());
	}
	virtual ~map() {
		this->_destructTree(this->_end);
	}

	map& operator=(const map& x) {
		if (this != &x) {
			this->clear();
			this->insert(x.begin(), x.end());
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

	bool empty() const {
		return this->_begin == this->_end;
	}
	size_type size() const {
		return this->_size;
	}
	size_type max_size() const {
		return std::min<size_type>(std::numeric_limits<size_type>::max(), this->_alloc.max_size());
	}

	mapped_type& operator[] (const key_type& k) {
		ft::pair<iterator, bool> tmp = this->insert(ft::make_pair(k, mapped_type()));
		return *(tmp.first).second;
	}

	ft::pair<iterator,bool> insert (const value_type& val) {
		(void)val;
	}
	iterator insert (iterator position, const value_type& val) {
		(void)position;
		(void)val;
	}
	template <class InputIterator>
	void insert (
		InputIterator first,
		InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) {
			(void)first;
			(void)last;
	}

	void erase (iterator position) {
		(void)position;
	}
	size_type erase (const key_type& k) {
		(void)k;
	}
	void erase (iterator first, iterator last) {
		(void)first;
		(void)last;
	}
	void swap (map& x) {
		_node_pointer tmpBegin = this->_begin;
		_node_pointer tmpEnd = this->_end;
		_node_allocator tmpAlloc = this->_alloc;
		key_compare tmpKeyCompare = this->_key_compare;
		value_compare tmpValueCompare = this->_value_compare;
		size_type tmpSize = this->_size;
		this->_begin = x._begin;
		this->_end = x._end;
		this->_alloc = x._alloc;
		this->_key_compare = x._key_compare;
		this->_value_compare = x._value_compare;
		this->_size = x._size;
		x._begin = tmpBegin;
		x.end = tmpEnd;
		x._alloc = tmpAlloc;
		x._key_compare = tmpKeyCompare;
		x._value_compare = tmpValueCompare;
		x._size = tmpSize;
	}
	void clear() {
		this->_destructTree(this->_end->_left);
		this->_end->_left = NULL;
		this->_size = 0;
		this->_begin = this->_end;
	}

	key_compare key_comp() const {
		return this->_key_compare;
	}
	value_compare value_comp() const {
		return this->_value_compare;
	}

	iterator find (const key_type& k) {
		_node_pointer node = this->_end->_left;
		while (node != NULL) {
			if (_value_compare(k, node->_value)) {
				node = node->_left;
			} else if (_value_compare(k, node->_value)) {
				node = node->_right;
			} else {
				return iterator(node);
			}
		}
		return iterator(this->_end);
	}
	const_iterator find (const key_type& k) const {
		_node_pointer node = this->_end->_left;
		while (node != NULL) {
			if (_value_compare(k, node->_value)) {
				node = node->_left;
			} else if (_value_compare(k, node->_value)) {
				node = node->_right;
			} else {
				return const_iterator(node);
			}
		}
		return const_iterator(this->_end);
	}
	size_type count (const key_type& k) const {
		ft::pair<const_iterator, const_iterator> p = this->equal_range(k);
		return size_type(std::distance(p.first, p.second));
	}
	iterator lower_bound (const key_type& k) {
		_node_pointer node = this->_end->_left;
		_node_pointer tmp = this->_end;
		while (node != NULL) {
			if (!_value_compare(node->_value, k)) {
				tmp = node;
				node = node->_left;
			} else {
				node = node->_right;
			}
		}
		return iterator(tmp);
	}
	const_iterator lower_bound (const key_type& k) const {
		_node_pointer node = this->_end->_left;
		_node_pointer tmp = this->_end;
		while (node != NULL) {
			if (!_value_compare(node->_value, k)) {
				tmp = node;
				node = node->_left;
			} else {
				node = node->_right;
			}
		}
		return const_iterator(tmp);
	}
	iterator upper_bound (const key_type& k) {
		_node_pointer node = this->_end->_left;
		_node_pointer tmp = this->_end;
		while (node != NULL) {
			if (_value_compare(k, node->_value)) {
				tmp = node;
				node = node->_left;
			} else {
				node = node->_right;
			}
		}
		return iterator(tmp);
	}
	const_iterator upper_bound (const key_type& k) const {
		_node_pointer node = this->_end->_left;
		_node_pointer tmp = this->_end;
		while (node != NULL) {
			if (_value_compare(k, node->_value)) {
				tmp = node;
				node = node->_left;
			} else {
				node = node->_right;
			}
		}
		return const_iterator(tmp);
	}
	ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
		_node_pointer node = this->_end->_left;
		_node_pointer tmp = this->_end;
		while (node != NULL) {
			if (_value_compare(k, node->_value)) {
				tmp = node;
				node = node->_left;
			} else if (_value_compare(node->_value, k)) {
				node = node->_right;
			} else {
				if (node->_right != NULL) {
					tmp = _mapNode<value_type>::_minimum(node->_right);
				}
				return ft::pair<const_iterator, const_iterator>(const_iterator(node), const_iterator(tmp));
			}
		}
		return ft::pair<const_iterator, const_iterator>(const_iterator(tmp), const_iterator(tmp));
	}
	ft::pair<iterator,iterator> equal_range (const key_type& k) {
		_node_pointer node = this->_end->_left;
		_node_pointer tmp = this->_end;
		while (node != NULL) {
			if (_value_compare(k, node->_value)) {
				tmp = node;
				node = node->_left;
			} else if (_value_compare(node->_value, k)) {
				node = node->_right;
			} else {
				if (node->_right != NULL) {
					tmp = _mapNode<value_type>::_minimum(node->_right);
				}
				return ft::pair<iterator, iterator>(iterator(node), iterator(tmp));
			}
		}
		return ft::pair<iterator, iterator>(iterator(tmp), iterator(tmp));
	}

	allocator_type get_allocator() const {
		return this->_alloc;
	}

};

template <class Key, class T, class Compare, class Alloc>
bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
	return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}
template <class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
	return !(lhs == rhs);
}
template <class Key, class T, class Compare, class Alloc>
bool operator< (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
template <class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
	return !(rhs < lhs);
}
template <class Key, class T, class Compare, class Alloc>
bool operator> (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
	return rhs < lhs;
}
template <class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
	return !(lhs < rhs);
}

template <class Key, class T, class Compare, class Alloc>
void swap (map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) {
	x.swap(y);
}

} // namespace ft

#endif
