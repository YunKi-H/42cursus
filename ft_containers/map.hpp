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

	_valueType * _valPtr() {
		return &this->_value;
	}

	static _nodePtr _nextNode(_nodePtr x) {
		if (x->_right != NULL) {
			x = x->_right;
			x = _minimum(x);
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
			x = _maximum(x);
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
	typedef T value_type;
	typedef value_type* pointer;
	typedef value_type& reference;
	typedef ft::_mapNode<value_type>* iterator_type;

	typedef typename std::bidirectional_iterator_tag iterator_category;
	typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;

	typedef typename ft::iterator_traits<iterator_type>::value_type node_type;
	typedef typename ft::iterator_traits<iterator_type>::pointer node_pointer;
	typedef typename ft::iterator_traits<iterator_type>::reference node_reference;

protected:
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

public:
	map_iterator() : _node() {}
	explicit map_iterator(node_pointer it) : _node(it) {}
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
		return *static_cast<node_pointer>(_node)->_valPtr();
	}
	pointer operator->() const {
		return static_cast<node_pointer>(_node)->_valPtr();
	}
	map_iterator& operator++() {
		// this->_node = this->_node->_nextNode(this->_node);
		this->_increment();
		return *this;
	}
	map_iterator operator++(int) {
		map_iterator temp(*this);
		++(*this);
		return temp;
	}
	map_iterator& operator--() {
		// this->_node = this->_node->_prevNode(this->_node);
		this->_decrement();
		return *this;
	}
	map_iterator operator--(int) {
		map_iterator temp(*this);
		--(*this);
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

	typedef ft::map_iterator<value_type> iterator;
	typedef ft::map_iterator<value_type> const_iterator;
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
		return node->_parent == this->_end;
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
			y->_left = NULL;
		}
		y->_parent = node->_parent;
		if (this->_isRoot(node)) {
			this->_end->_left = y;
			y->_parent = this->_end;
			node->_parent = NULL;
		} else if (_isLeftChild(node)) {
			node->_parent->_left = y;
		} else {
			node->_parent->_right = y;
		}
		node->_parent = y;
		y->_left = node;
	}
	void _rotateRight(_node_pointer node) {
		_node_pointer y = node->_left;
		node->_left = y->_right;
		if (y->_right != NULL) {
			y->_right->_parent = node;
			y->_right = NULL;
		}
		y->_parent = node->_parent;
		if (this->_isRoot(node)) {
			this->_end->_right = y;
			y->_parent = this->_end;
			node->_parent = NULL;
		} else if (_isRightChild(node)) {
			node->_parent->_right = y;
		} else {
			node->_parent->_left = y;
		}
		node->_parent = y;
		y->_right = node;
	}

	// 새로 삽입될 노드의 부모가 될 value와 가장 가까운 노드를 반환
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
		return (*(tmp.first)).second;
	}

	ft::pair<iterator,bool> insert (const value_type& val) {
		_node_pointer parent = this->_searchPosition(val);
		_node_pointer node = NULL;

		if (parent == this->_end) {
			node = this->_alloc.allocate(1);
			this->_alloc.construct(node, val);
			node->_color = BLACK;
			node->_parent = this->_end;
			this->_end->_left = node;

			this->_begin = node;
		} else if (_value_compare(val, parent->_value)) {
			node = this->_alloc.allocate(1);
			this->_alloc.construct(node, val);
			node->_parent = parent;
			parent->_left = node;

			if (this->_begin == parent) {
				this->_begin = node;
			}
		} else if (_value_compare(parent->_value, val)) {
			node = this->_alloc.allocate(1);
			this->_alloc.construct(node, val);
			node->_parent = parent;
			parent->_right = node;
		} else {
			return ft::make_pair(iterator(parent), false);
		}
		_node_pointer retNode = node;

		// insertFix algorithm
		_node_pointer grandParent = parent->_parent;
		_node_pointer uncle = NULL;
		while (node->_parent->_color == RED) {
			parent = node->_parent;
			if (_isLeftChild(parent)) {
				uncle = grandParent->_right;
				if (uncle != NULL && uncle->_color == RED) {
					uncle->_color = BLACK;
					parent->_color = BLACK;
					grandParent->_color = RED;
					node = grandParent;
				} else {
					if (_isRightChild(node)) {
						node = parent;
						_rotateLeft(node);
					}
					parent->_color = BLACK;
					grandParent->_color = RED;
					_rotateRight(grandParent);
				}
			} else {
				uncle = grandParent->_left;
				if (uncle != NULL && uncle->_color == RED) {
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandParent->_color = RED;
					node = grandParent;
				} else {
					if (_isLeftChild(node)) {
						node = parent;
						_rotateRight(node);
					}
					parent->_color = BLACK;
					grandParent->_color = RED;
					_rotateLeft(grandParent);
				}
			}
			this->_end->_left->_color = BLACK;
		}
		this->_size += 1;
		return ft::make_pair(iterator(retNode), true);
	}
	iterator insert (iterator position, const value_type& val) {
		(void)position;
		ft::pair<iterator, bool> tmp = this->insert(val);
		return tmp.first;
	}
	template <class InputIterator>
	void insert (
		InputIterator first,
		InputIterator last) {
			while (first != last) {
				this->insert(*first);
				first++;
			}
	}

	void erase (iterator position) {
		if (position == this->begin()) {
			this->_begin = this->_begin->_nextNode(this->_begin);
		}

		_node_pointer nodeToBeDeleted = position.base();
		bool originalColor = nodeToBeDeleted->_color;

		_node_pointer x;
		_node_pointer y;
		if (nodeToBeDeleted->_left == NULL) {
			x = nodeToBeDeleted->_right;
			if (nodeToBeDeleted->_parent->_left == nodeToBeDeleted) {
				nodeToBeDeleted->_parent->_left = x;
			} else {
				nodeToBeDeleted->_parent->_right = x;
			}
			x->_parent = nodeToBeDeleted->_parent;
		} else if (nodeToBeDeleted->_right == NULL) {
			x = nodeToBeDeleted->_left;
			if (nodeToBeDeleted->_parent->_left == nodeToBeDeleted) {
				nodeToBeDeleted->_parent->_left = x;
			} else {
				nodeToBeDeleted->_parent->_right = x;
			}
			x->_parent = nodeToBeDeleted->_parent;
		} else {
			y = nodeToBeDeleted->_right->_minimum(nodeToBeDeleted->_right);
			originalColor = y->_color;
			x = y->_right;
			if (y->_parent == nodeToBeDeleted) {
				x->_parent = y;
			} else {
				std::cout <<"2\n";
				if (y->_parent->_left == y) {
					y->_parent->_left = x;
				} else {
					y->_parent->_right = x;
				}
				std::cout <<"22\n";
				x->_parent = y->_parent;
			}
			std::cout <<"3\n";
			if (nodeToBeDeleted->_parent->_left == nodeToBeDeleted) {
				nodeToBeDeleted->_parent->_left = y;
			} else {
				nodeToBeDeleted->_parent->_right = y;
			}
			std::cout <<"4\n";
			y->_parent = nodeToBeDeleted->_parent;
			_node_pointer tmp = position.base();
			y->_color = tmp->_color;
		}

		// deleteFix
		if (originalColor == BLACK) {
			while (!_isRoot(x) && x->_color == BLACK) {
				if (x->_parent->_left == x) {
					_node_pointer w = x->_parent->_right;
					if (w->_color == RED) {
						w->_color = BLACK;
						x->_parent->_color = RED;
						_rotateLeft(x->_parent);
						w = x->_parent->_right;
					}
					if (w->_left->_color == BLACK && w->_right->_color == BLACK) {
						w->_color = BLACK;
						x = x->_parent;
					} else if (w->_right->_color == BLACK) {
						w->_left->_color = BLACK;
						w->_color = RED;
						_rotateRight(w);
						w = x->_parent->_right;
					}
					if (w->_right->_color == RED) {
						w->_color = x->_parent->_color;
						x->_parent->_color = BLACK;
						w->_right->_color = BLACK;
						_rotateLeft(x->_parent);
						x = this->_end->_left;
					}
				} else {
					_node_pointer w = x->_parent->_left;
					if (w->_color == RED) {
						w->_color = BLACK;
						x->_parent->_color = RED;
						_rotateLeft(x->_parent);
						w = x->_parent->_left;
					}
					if (w->_right->_color == BLACK && w->_left->_color == BLACK) {
						w->_color = BLACK;
						x = x->_parent;
					} else if (w->_left->_color == BLACK) {
						w->_right->_color = BLACK;
						w->_color = RED;
						_rotateRight(w);
						w = x->_parent->_left;
					}
					if (w->_left->_color == RED) {
						w->_color = x->_parent->_color;
						x->_parent->_color = BLACK;
						w->_left->_color = BLACK;
						_rotateLeft(x->_parent);
						x = this->_end->_right;
					}
				}
			}
			x->_color = BLACK;
		}
		this->_alloc.destroy(position.base());
		this->_alloc.deallocate(position.base(), 1);
		this->_size -= 1;
	}
	size_type erase (const key_type& k) {
		iterator it = this->find(k);
		if (it == this->end()) {
			return 0;
		}
		this->erase(it);
		return 1;
	}
	void erase (iterator first, iterator last) {
		if (first == this->begin() && last == this->end()) {
			this->clear();
			return;
		}
		while (first != last) {
			this->erase(first);
			first++;
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
		this->_destructTree(this->_end->_right);
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
