#pragma once
#include <iostream>

#define DEBUG 0

namespace my
{
template<typename T>
class list
{
public:
	class list_iterator;		// ��������������� ���������� ������ ���������
								// ��� ���������� ������� begin(), end(), insert()
	using iterator = typename list<T>::list_iterator;

public:
	list();						// ����������� �� ���������
	list(const list& _Rhslist);	// ����������� �����������
	~list();					// ����������

public:
	void insert(list_iterator _Pos, const T& _Data); // ��������� ���� ����� _Pos
	void erase(const list_iterator& _Pos);			 // ������� ���� _Pos


public:
	void clear();					 // ������� ��� ���� ������
	void push_back(const T& _Data);  // ��������� ���� � ����� ������
	void push_front(const T& _Date); // ��������� ���� � ������ ������
	void pop_back();				 // ������� �������� ����
	void pop_front();				 // ������� ��������� ����
	void assign(size_t _Count, const T& _Data); // ������ _Count ����� �� ���������_Data
	iterator find(const T& _Value);	 // ���������� �������� ������� ��������� ���� �� ��������� _Value

public:
	size_t size() { return m_size; }		 // ���������� ���������� ����� ������
	bool empty() { return !((bool)m_size); } // true, ���� ������ �� ����, ����� false
	T& front(); // ���������� ������ �� ������ �������
	T& back();  // ���������� ������ �� ��������� �������

public:
	void swap(iterator& _itFrom, iterator& itTo); // ������ ���� ������� �� ����������
	void swap(const iterator& _itFrom, const iterator& _itTo); // ������ ���� ������� �� ����������
	void sort_az(); // ���������� <=
	void sort_za(); // ���������� >=

public:
	void getInfo();
	void print(char _Delim);	// ������� �������� ������ � �������, �������� �������� _Delim

public:
	iterator begin() { return iterator(m_head); }	  // ���������� �������� ������� ����
	iterator end() { return iterator(m_tail->next); } // ���������� �������� ���������� ����

public:
	T& operator[](size_t _Idx);
	const T& operator[](size_t _Idx) const;

	friend void advance(iterator& _Iter, const int _Shift);

private:
	template<typename T>
	class node
	{
	public:
		node(T _data = T(), // T() ����������� �������� �� ��������� ��� ���� T
			 node<T>* _prev = nullptr,		// ��������� �� ���������� ����
			 node<T>* _next = nullptr) :	// ��������� �� ��������� ����
			prev(_prev),
			next(_next),
			data(_data)
		{};
		~node() {};

	public:
		node<T>* prev;
		node<T>* next;
		T data;
	};

	class list_iterator
	{
		friend list;
	public:
		list_iterator(node<T>* _node)
		{
			m_curr = _node;
		}

		~list_iterator() {};

	public:
		list_iterator& operator++()
		{
			m_curr = m_curr->next;
			return *this;
		}

		list_iterator& operator++(int)
		{
			node<T>* tmp = m_curr;
			m_curr = m_curr->next;
			return tmp;
		}

		list_iterator& operator--()
		{
			m_curr = m_curr->prev;
			return *this;
		}

		list_iterator& operator--(int)
		{
			node<T>* tmp = m_curr;
			m_curr = m_curr->prev;
			return tmp;
		}

		T& operator*()
		{
			return m_curr->data;
		}

		node<T>* operator->() const noexcept
		{
			return m_curr;
		}

		bool operator==(const list_iterator& _Rhsiter)
		{
			return m_curr == _Rhsiter.m_curr;
		}

		bool operator!=(const list_iterator& _Rhsiter)
		{
			return m_curr != _Rhsiter.m_curr;
		}

		T& getData()
		{
			return m_curr->data;
		}

	private:
		void swap(const list_iterator& _Iter)
		{
			std::swap(m_curr->data, _Iter.m_curr->data);
			std::swap(m_curr->next, _Iter.m_curr->next);
			std::swap(m_curr->prev, _Iter.m_curr->prev);
		}

	private:
		node<T>* m_curr;
	};

	node<T>* m_head; // ��������� �� ������
	node<T>* m_tail; // ��������� �� �����
	size_t m_size;	 // ���������� ���������
};

//////////////////
// Implementation
//////////////////

template<typename T>
inline list<T>::list() :
	m_head(nullptr),
	m_tail(nullptr),
	m_size(0)
{}

template<typename T>
inline list<T>::list(const list& _Rhslist)
{
	clear();
	node<T>* rhs_curr = _Rhslist.m_head;
	while (rhs_curr != nullptr) {
		push_back(rhs_curr->data);
		rhs_curr = rhs_curr->next;
	}
}

template<typename T>
inline list<T>::~list()
{
	if (m_size) {
		while (m_tail != nullptr) {
			node<T>* curr = m_tail;
			m_tail = m_tail->prev;
			delete curr;
		}
	}
}

template<typename T>
inline void list<T>::clear()
{	// ���� ���� ���� � ������, �� ������� ���, ������� � ����������
	if (m_size) {
		node<T>* curr = m_tail;
		while (m_size > 0) {
			pop_back();
		}
	}
}

// ��������� ���� ����� _Pos
// Inserts new node before _Pos
template<typename T>
inline void list<T>::insert(list_iterator _Pos, const T& _Data)
{
	if (_Pos.operator->() == m_head) { // ���� �������� ��������� �� ������,
		push_front(_Data);			   // �������� ��������������� �����
		return;
	}
	if (_Pos.operator->() == m_tail) { // ���� �������� ��������� �� �����,
		push_back(_Data);			   // �������� ��������������� �����
		return;
	}
	list<T>::list_iterator iter = begin();
	while (iter != nullptr) {
		if (iter == _Pos) {
			node<T>* newNode = new node<T>(_Data, iter->prev, iter.operator->());
			iter->prev->next = newNode;
			iter->prev = newNode;
			++m_size;
			return;
		}
		++iter;
	}
}

template<typename T>
inline void list<T>::erase(const list_iterator& _Pos)
{
	if (_Pos.operator->() == m_head) { // ���� �������� ��������� �� ������,
		pop_front();				   // �������� ��������������� �����
		return;
	}
	if (_Pos.operator->() == m_tail) { // ���� �������� ��������� �� �����,
		pop_back();					   // �������� ��������������� �����
		return;
	}

	list<T>::list_iterator iter = begin();
	while (iter != nullptr) { // � ����� ������ ��������� ���������� �� ������,
		if (iter == _Pos) {				   // ������� ������� ����,
			iter->prev->next = iter->next; // ������������� �����
			iter->next->prev = iter->prev; // � ������ �������
			delete (_Pos.operator->());	   // � ������� ������� ����
			--m_size;
			return;
		}
		++iter;
	}
}

// ������� �������� �� _Shift ����� ����� �� ������
template<typename T>
void advance(typename list<T>::iterator& _Iter, const int _Shift)
{
	int count(0);
	if (_Shift > 0) {
		while (count < _Shift) {
			++_Iter;
			++count;
		}
		return;
	}
	else if (_Shift < 0) {
		while (count > _Shift) {
			--_Iter;
			--count;
		}
		return;
	}
	else return;
}

template<typename T>
inline void list<T>::push_back(const T& _Data)
{
	if (m_size == 0) {					// ���� ������ ����,
		m_head = new node<T>(_Data);	// ������� ������ ����
		m_tail = m_head;
	}
	else {											// ����� �������� ����
		m_tail->next = new node<T>(_Data, m_tail);	// � ����� ������
		m_tail = m_tail->next;						// � �������� ��������� �����
	}
	m_size++; // ����������� ������ ������
}

template<typename T>
inline void list<T>::push_front(const T& _Data)
{
	if (m_size == 0) {				 // ���� ������ ����,
		m_head = new node<T>(_Data); // ������� ������ ����
		m_tail = m_head;
	}
	else {													// ����� �������� ����
		m_head->prev = new node<T>(_Data, nullptr, m_head);	// ����� ������� ������
		m_head = m_head->prev;								// � �������� ��������� ������
	}
	m_size++; // ����������� ������ ������
}

template<typename T>
inline void list<T>::pop_back()
{
#if DEBUG
	std::cout << "pop_back()" << std::endl;
#endif // DEBUG
	if (m_tail != nullptr) {
		node<T>* tmp = m_tail;
		m_tail = m_tail->prev;
		if (m_tail != nullptr) {	// ����
			m_tail->next = nullptr;
		}
		delete tmp;
		m_size--;
		if (m_size == 0) {
			delete m_tail;
			m_head = m_tail = nullptr;
		}
	}
}

template<typename T>
inline void list<T>::pop_front()
{
#if DEBUG
	std::cout << "pop_front()" << std::endl;
#endif // DEBUG
	if (m_head != nullptr) {
		node<T>* tmp = m_head;
		m_head = m_head->next;
		if (m_head != nullptr) {
			m_head->prev = nullptr;
		}
		delete tmp;
		m_size--;
		if (m_size == 0) {
			delete m_head;
			m_head = m_tail = nullptr;
		}
	}
}

template<typename T>
inline void list<T>::assign(size_t _Count, const T& _Data)
{
	if (m_size > 0) { clear(); }
	size_t count(0);
	while (count < _Count) {
		push_back(_Data);
		++count;
	}
}

// ���������� �������� ������� ��������� ���� �� ��������� _Value
template<typename T>
inline typename list<T>::list_iterator list<T>::find(const T& _Value)
{
	list<T>::list_iterator iter = begin();
	while (iter != end()) {
		if (iter.getData() == _Value) {
			return iter;
		}
		++iter;
	}
	return nullptr;
}

template<typename T>
inline T& list<T>::front()
{
	return m_head->data;
}

template<typename T>
inline T& list<T>::back()
{
	return m_tail->data;
}

template<typename T>
inline void list<T>::swap(iterator& _itFrom, iterator& _itTo)
{
	std::swap(_itFrom->data, _itTo->data);
}

template<typename T>
inline void list<T>::swap(const iterator& _itFrom, const iterator& _itTo)
{
	std::swap(_itFrom->data, _itTo->data);
}

template<typename T>
inline void list<T>::sort_az()
{
	bool isSwapped(0);
	do {
		isSwapped = false;
		auto iter = this->begin();
		auto itnext = this->begin();
		++itnext;
		for (; itnext != this->end(); ++itnext, ++iter) {
			if (iter->data > itnext->data) {
				this->swap(iter, itnext);
				isSwapped = true;
			}
		}
	}
	while (isSwapped);
}

template<typename T>
inline void list<T>::sort_za()
{
	bool isSwapped(0);
	do {
		isSwapped = false;
		auto iter = this->begin();
		auto itnext = this->begin();
		++itnext;
		for (; itnext != this->end(); ++itnext, ++iter) {
			if (iter->data < itnext->data) {
				this->swap(iter, itnext);
				isSwapped = true;
			}
		}
	}
	while (isSwapped);
}

// DEBUG info
template<typename T>
inline void list<T>::getInfo()
{
#if DEBUG
	std::cout << "======== Address info ========" << std::endl;
	node<T>* curr = m_head;
	size_t count(0);
	if (curr != nullptr) {
		while (curr != nullptr) {
			std::cout << '#' << count << '\t'
				<< "prev: " << curr->prev
				<< " curr: " << curr
				<< " next: " << curr->next << std::endl;
			curr = curr->next;
			count++;
		}
		std::cout
			<< "     tm_tail: " << m_tail
			<< " next: " << m_tail->next
			<< " prev: " << m_tail->prev << std::endl;
	}
	else {
		std::cout << "List is empty" << std::endl;
		std::cout
			<< "  curr: " << curr << std::endl
			<< "m_head: " << m_head;
		if (m_head != nullptr) {
			std::cout
				<< " next: " << m_head->next
				<< " prev: " << m_head->prev
				<< std::endl;
		}
		else { std::cout << std::endl; }
		std::cout << "m_tail: " << m_tail;
		if (m_tail != nullptr) {
			std::cout
				<< " next: " << m_tail->next
				<< " prev: " << m_tail->prev
				<< std::endl;
		}
		else { std::cout << std::endl; }
	}
	std::cout << "======== End of info ========" << std::endl;
#endif // DEBUG
}

// ������� �������� ������ � �������, �������� �������� _Delim
template<typename T>
inline void list<T>::print(char _Delim)
{
	for (auto& iter : *this) {
		std::cout << iter << _Delim;
	}
}

// ���������� �������� ���� � �������� _Idx
template<typename T>
inline T& list<T>::operator[](size_t _Idx)
{
	node<T>* curr = m_head;
	size_t count(0);
	while (curr != nullptr) {
		if (count == _Idx) {
			return curr->data;
		}
		count++;
		curr = curr->next;
	}
	//return nullptr;
}

// ���������� �������� ���� � �������� _Idx
template<typename T>
inline const T& list<T>::operator[](size_t _Idx) const
{
	node<T>* curr = m_head;
	size_t count(0);
	while (curr != nullptr) {
		if (count == _Idx) {
			return curr->data;
		}
		count++;
		curr = curr->next;
	}
	//return nullptr;
}
}