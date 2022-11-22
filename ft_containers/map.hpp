#ifndef MAP_HPP
#define MAP_HPP

// https://www.programiz.com/dsa/red-black-tree
#include <iostream>
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
	_nodeColor _color;
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

	_valueType* _valPtr() {
		return &this->_value;
	}

};

template <class val, class ref, class ptr>
class map_iterator {
public:
	typedef val value_type;
	typedef ref reference;
	typedef ptr pointer;
	typedef map_iterator<val, val&, val*> iterator;
	typedef map_iterator<val, const val&, const val*> const_iterator;
	typedef map_iterator<val, ref, ptr> self;

	typedef ft::_mapNode<value_type>* link_type;

	typedef typename std::bidirectional_iterator_tag iterator_category;
	typedef typename ft::iterator_traits<link_type>::difference_type difference_type;
	typedef typename ft::iterator_traits<link_type>::value_type node_type;
	typedef typename ft::iterator_traits<link_type>::pointer node_pointer;
	typedef typename ft::iterator_traits<link_type>::reference node_reference;

	node_pointer _node;

	void _increment() {
		if (this->_node->_right != NULL) {
			this->_node = this->_node->_right;
			while (this->_node->_left != NULL) {
				this->_node = this->_node->_left;
			}
		} else {
			node_pointer y = this->_node->_parent;
			while (this->_node == y->_right) {
				this->_node = y;
				y = y->_parent;
			}
			if (this->_node->_right != y) {
				this->_node = y;
			}
		}
	}
	void _decrement() {
		if (this->_node->_left != NULL) {
			this->_node = this->_node->_left;
			while (this->_node->_right != NULL) {
				this->_node = this->_node->_right;
			}
		} else {
			node_pointer y = this->_node->_parent;
			while (this->_node == y->_left) {
				this->_node = y;
				y = y->_parent;
			}
			this->_node = y;
		}
	}

	map_iterator() : _node() {}
	map_iterator(link_type it) : _node(it) {}
	map_iterator(const iterator & it) : _node(it._node) {}
	virtual ~map_iterator() {}

	friend bool operator==(const map_iterator& lhs, const map_iterator& rhs) {
		return lhs._node == rhs._node;
	}
	friend bool operator!=(const map_iterator& lhs, const map_iterator& rhs) {
		return lhs._node != rhs._node;
	}
	reference operator*() const {
		return *static_cast<node_pointer>(_node)->_valPtr();
	}
	pointer operator->() const {
		return &(operator*());
	}
	self& operator++() {
		this->_increment();
		return *this;
	}
	self operator++(int) {
		self temp = *this;
		this->_increment();
		return temp;
	}
	self& operator--() {
		this->_decrement();
		return *this;
	}
	self operator--(int) {
		self temp = *this;
		this->_decrement();
		return temp;
	}

	node_pointer base() const {
		return this->_node;
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

	typedef ft::map_iterator<value_type, reference, pointer> iterator;
	typedef ft::map_iterator<value_type, const_reference, const_pointer> const_iterator;
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
		bool operator() (const value_type& x, const value_type& y) const {
			return comp(x.first, y.first);
		}
		bool operator()(const value_type& x, const key_type& y) const {
			return comp(x.first, y);
		}
		bool operator()(const key_type& x, const value_type& y) const {
			return comp(x, y.first);
		}
	};

protected:
	typedef _mapNode<value_type> _node_type;
	typedef _mapNode<value_type>* _node_pointer; // LinkType
	typedef typename allocator_type::template rebind<_node_type>::other _node_allocator;

	_node_pointer _begin;
	_node_pointer _end;
	_node_allocator _alloc;
	key_compare _key_compare;
	value_compare _value_compare;
	size_type _size;

	bool _isRoot(_node_pointer node) {
		return this->_end->_left == node;
	}
	bool _isLeftChild(_node_pointer node) {
		return node->_parent->_left == node;
	}
	bool _isRightChild(_node_pointer node) {
		return node->_parent->_right == node;
	}

	void _destructTree(_node_pointer node) {
		if (node == NULL) {
			return;
		}
		_destructTree(node->_left);
		_destructTree(node->_right);
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}

	void _rotateLeft(_node_pointer node) {
		_node_pointer y = node->_right;
		node->_right = y->_left;
		if (y->_left != NULL) {
			y->_left->_parent = node;
		}
		y->_parent = node->_parent;
		if (this->_isRoot(node)) {
			this->_end->_left = y;
		} else if (_isLeftChild(node)) {
			node->_parent->_left = y;
		} else {
			node->_parent->_right = y;
		}
		y->_left = node;
		node->_parent = y;
	}
	void _rotateRight(_node_pointer node) {
		_node_pointer y = node->_left;
		node->_left = y->_right;
		if (y->_right != NULL) {
			y->_right->_parent = node;
		}
		y->_parent = node->_parent;
		if (this->_isRoot(node)) {
			this->_end->_left = y;
		} else if (_isRightChild(node)) {
			node->_parent->_right = y;
		} else {
			node->_parent->_left = y;
		}
		y->_right = node;
		node->_parent = y;
	}

	iterator _insert_unique(_node_pointer x, _node_pointer y, const value_type& val) {
		_node_pointer z;

		if (y == this->_end || x != NULL || _value_compare(val, y->_value)) {
			z = this->_alloc.allocate(1);
			this->_alloc.construct(z, val);
			y->_left = z;
			if (y == this->_end) {
				this->_end->_left = z;
				this->_begin = z;
			} else if (y == this->_begin) {
				this->_begin = z;
			}
		} else {
			z = this->_alloc.allocate(1);
			this->_alloc.construct(z, val);
			y->_right = z;
		}
		z->_parent = y;
		z->_left = NULL;
		z->_right = NULL;
		_rebalance(z);
		++this->_size;
		return iterator(z);
	}

	void _rebalance(_node_pointer x) {
		x->_color = RED;
		while (!_isRoot(x) && x->_parent->_color == RED) {
			if (_isLeftChild(x->_parent)) {
				_node_pointer y = x->_parent->_parent->_right;
				if (y != NULL && y->_color == RED) {
					x->_parent->_color = BLACK;
					y->_color = BLACK;
					x->_parent->_parent->_color = RED;
					x = x->_parent->_parent;
				} else {
					if (_isRightChild(x)) {
						x = x->_parent;
						_rotateLeft(x);
					}
					x->_parent->_color = BLACK;
					x->_parent->_parent->_color = RED;
					_rotateRight(x->_parent->_parent);
				}
			} else {
				_node_pointer y = x->_parent->_parent->_left;
				if (y != NULL && y->_color == RED) {
					x->_parent->_color = BLACK;
					y->_color = BLACK;
					x->_parent->_parent->_color = RED;
					x = x->_parent->_parent;
				} else {
					if (_isLeftChild(x)) {
						x = x->_parent;
						_rotateRight(x);
					}
					x->_parent->_color = BLACK;
					x->_parent->_parent->_color = RED;
					_rotateLeft(x->_parent->_parent);
				}
			}
		}
		this->_end->_left->_color = BLACK;
	}

	_node_pointer _rebalance_erase(_node_pointer z) {
		_node_pointer y = z;
		_node_pointer x = NULL;
		_node_pointer x_parent = NULL;
		if (y->_left == NULL) {
			x = y->_right;
		} else if (y->_right == NULL) {
			x = y->_left;
		} else {
			y = y->_right;
			while (y->_left != NULL) {
				y = y->_left;
			}
			x = y->_right;
		}
		if (y != z) {
			z->_left->_parent = y;
			y->_left = z->_left;
			if (y != z->_right) {
				x_parent = y->_parent;
				if (x != NULL) {
					x->_parent = y->_parent;
				}
				y->_parent->_left = x;
				y->_right = z->_right;
				z->_right->_parent = y;
			} else {
				x_parent = y;
			}
			if (_isRoot(z)) {
				this->_end->_left = y;
			} else if (_isLeftChild(z)) {
				z->_parent->_left = y;
			} else {
				z->_parent->_right = y;
			}
			y->_parent = z->_parent;
			std::swap(y->_color, z->_color);
			y = z;
		} else {
			x_parent = y->_parent;
			if (x != NULL) {
				x->_parent = y->_parent;
			}
			if (_isRoot(z)) {
				this->_end->_left = x;
			} else {
				if (_isLeftChild(z)) {
					z->_parent->_left = x;
				} else {
					z->_parent->_right = x;
				}
			}
			if (this->_begin == z) {
				if (z->_right == NULL) {
					this->_begin = z->_parent;
				} else {
					this->_begin = x->_minimum(x);
				}
			}
		}
		if (y->_color != RED) {
			while (!_isRoot(x) && (x == NULL || x->_color == BLACK)) {
				if (x == x_parent->_left) {
					_node_pointer w = x_parent->_right;
					if (w->_color == RED) {
						w->_color = BLACK;
						x_parent->_color = RED;
						_rotateLeft(x_parent);
						w = x_parent->_right;
					}
					if ((w->_left == NULL || w->_left->_color == BLACK) &&
					(w->_right == NULL || w->_right->_color == BLACK)) {
						w->_color = RED;
						x = x_parent;
						x_parent = x_parent->_parent;
					} else {
						if (w->_right == NULL || w->_right->_color == BLACK) {
							if (w->_left != NULL) {
								w->_left->_color = BLACK;
							}
							w->_color = RED;
							_rotateRight(w);
							w = x_parent->_right;
						}
						w->_color = x_parent->_color;
						x_parent->_color = BLACK;
						if (w->_right != NULL) {
							w->_right->_color = BLACK;
						}
						_rotateLeft(x_parent);
						break;
					}
				} else {
					_node_pointer w = x_parent->_left;
					if (w == NULL)
					if (w->_color == RED) {
						w->_color = BLACK;
						x_parent->_color = RED;
						_rotateRight(x_parent);
						w = x_parent->_left;
					}
					if ((w->_right == NULL || w->_right->_color == BLACK) &&
					(w->_left == NULL || w->_left->_color == BLACK)) {
						w->_color = RED;
						x = x_parent;
						x_parent = x_parent->_parent;
					} else {
						if (w->_left == NULL || w->_left->_color == BLACK) {
							if (w->_right != NULL) {
								w->_right->_color = BLACK;
							}
							w->_color = RED;
							_rotateLeft(w);
							w = x_parent->_left;
						}
						w->_color = x_parent->_color;
						x_parent->_color = BLACK;
						if (w->_left != NULL) {
							w->_left->_color = BLACK;
						}
						_rotateRight(x_parent);
						break;
					}
				}
			}
				if (x != NULL) {
					x->_color = BLACK;
				}
		}
		return y;
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
		const allocator_type& alloc = allocator_type())
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
	: _alloc(x.get_allocator()),
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
		return this->_size == 0;
	}
	size_type size() const {
		return this->_size;
	}
	size_type max_size() const {
		return std::min<size_type>(std::numeric_limits<size_type>::max(), this->_alloc.max_size());
	}

	mapped_type& operator[] (const key_type& k) {
		iterator it = this->lower_bound(k);
		if (it == this->end() || _value_compare(k, it._node->_value)) {
			it = insert(it, ft::make_pair(k, mapped_type()));
		}
		return (*it).second;
	}

	ft::pair<iterator,bool> insert (const value_type& val) {
		_node_pointer y = this->_end;
		_node_pointer x = this->_end->_left;
		bool comp = true;

		while (x != NULL) {
			y = x;
			comp = _value_compare(val, x->_value);
			x = comp ? x->_left : x->_right;
		}

		iterator j = iterator(y);
		if (comp) {
			if (j == this->begin()) {
				return ft::make_pair(_insert_unique(x, y, val), true);
			} else {
				--j;
			}
		}

		if (_value_compare(j.base()->_value, val)) {
			return ft::make_pair(_insert_unique(x, y, val), true);
		}
		return ft::make_pair(j, false);
	}
	iterator insert (iterator position, const value_type& val) {
		(void)position;
		ft::pair<iterator, bool> tmp = this->insert(val);
		return tmp.first;
	}
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last) {
		while (first != last) {
			this->insert(*first);
			++first;
		}
	}

	void erase (iterator position) {
		_node_pointer y = _rebalance_erase(position._node);
		this->_alloc.destroy(y);
		this->_alloc.deallocate(y, 1);
		--this->_size;
	}
	size_type erase (const key_type& k) {
		ft::pair<iterator, iterator> p = this->equal_range(k);
		size_type n = std::distance(p.first, p.second);
		erase(p.first, p.second);
		return n;
	}
	void erase (iterator first, iterator last) {
		if (first == this->begin() && last == this->end()) {
			this->clear();
		} else {
			while (first != last) {
				this->erase(first++);
			}
		}
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
		x._end = tmpEnd;
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
		_node_pointer x = this->_end->_left;
		_node_pointer y = this->_end;
		while (x != NULL) {
			if (!_value_compare(x->_value, k)) {
				y = x;
				x = x->_left;
			} else {
				x = x->_right;
			}
		}
		iterator j = iterator(y);
		return (j == this->end() || _value_compare(k, j._node->_value)) ? this->end() : j;
	}
	const_iterator find (const key_type& k) const {
		_node_pointer x = this->_end->_left;
		_node_pointer y = this->_end;
		while (x != NULL) {
			if (!_value_compare(x->_value, k)) {
				y = x;
				x = x->_left;
			} else {
				x = x->_right;
			}
		}
		const_iterator j = const_iterator(y);
		return (j == this->end() || _value_compare(k, j._node->_value)) ? this->end() : j;
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
