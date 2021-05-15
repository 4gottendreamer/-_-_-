// C++ program to implement Custom Linked List and
// iterator pattern.
//#include <bits/stdc++.h>
#include <iostream>

//using namespace std;

// Custom class to handle Linked List operations
// Operations like push_back, push_front, pop_back,
// pop_front, erase, size can be added here
//template <typename T>
//class LinkedList
//{
//	// Forward declaration
//	class Node;
//
//public:
//	LinkedList<T>() noexcept
//	{
//		// caution: static members can't be
//		// initialized by initializer list
//		m_spRoot = nullptr;
//	}
//
//	// Forward declaration must be done
//	// in the same access scope
//	class Iterator;
//
//	// Root of LinkedList wrapped in Iterator type
//	Iterator begin()
//	{
//		return Iterator(m_spRoot);
//	}
//
//	// End of LInkedList wrapped in Iterator type
//	Iterator end()
//	{
//		return Iterator(nullptr);
//	}
//
//	// Adds data to the end of list
//	void push_back(T data);
//
//	void Traverse();
//
//	// Iterator class can be used to
//	// sequentially access nodes of linked list
//	class Iterator
//	{
//	public:
//		Iterator() noexcept :
//			m_pCurrentNode(m_spRoot)
//		{}
//
//		Iterator(const Node* pNode) noexcept :
//			m_pCurrentNode(pNode)
//		{}
//
//		Iterator& operator=(Node* pNode)
//		{
//			this->m_pCurrentNode = pNode;
//			return *this;
//		}
//
//		// Prefix ++ overload
//		Iterator& operator++()
//		{
//			if (m_pCurrentNode)
//				m_pCurrentNode = m_pCurrentNode->pNext;
//			return *this;
//		}
//
//		// Postfix ++ overload
//		Iterator operator++(int)
//		{
//			Iterator iterator = *this;
//			++* this;
//			return iterator;
//		}
//
//		bool operator!=(const Iterator& iterator)
//		{
//			return m_pCurrentNode != iterator.m_pCurrentNode;
//		}
//
//		int operator*()
//		{
//			return m_pCurrentNode->data;
//		}
//
//	private:
//		const Node* m_pCurrentNode;
//	};
//
//private:
//
//	class Node
//	{
//		T data;
//		Node* pNext;
//
//		// LinkedList class methods need
//		// to access Node information
//		friend class LinkedList;
//	};
//
//	// Create a new Node
//	Node* GetNode(T data)
//	{
//		Node* pNewNode = new Node;
//		pNewNode->data = data;
//		pNewNode->pNext = nullptr;
//
//		return pNewNode;
//	}
//
//	// Return by reference so that it can be used in
//	// left hand side of the assignment expression
//	Node*& GetRootNode()
//	{
//		return m_spRoot;
//	}
//
//	static Node* m_spRoot;
//};
//
//template <typename T>
///*static*/ typename LinkedList<T>::Node* LinkedList<T>::m_spRoot = nullptr;
//
//template <typename T>
//void LinkedList<T>::push_back(T data)
//{
//	Node* pTemp = GetNode(data);
//	if (!GetRootNode()) {
//		GetRootNode() = pTemp;
//	}
//	else {
//		Node* pCrawler = GetRootNode();
//		while (pCrawler->pNext) {
//			pCrawler = pCrawler->pNext;
//		}
//
//		pCrawler->pNext = pTemp;
//	}
//}
//
//template <typename T>
//void LinkedList<T>::Traverse()
//{
//	Node* pCrawler = GetRootNode();
//
//	while (pCrawler) {
//		cout << pCrawler->data << " ";
//		pCrawler = pCrawler->pNext;
//	}
//
//	cout << endl;
//}
////Driver program
//int main0()
//{
//
//	LinkedList<int> list;
//
//	// Add few items to the end of LinkedList
//	list.push_back(1);
//	list.push_back(2);
//	list.push_back(3);
//
//	std::cout << "Traversing LinkedList through method" << std::endl;
//	list.Traverse();
//
//	std::cout << "Traversing LinkedList through Iterator" << std::endl;
//	for (LinkedList<int>::Iterator iterator = list.begin();
//		 iterator != list.end(); iterator++) {
//		std::cout << *iterator << " ";
//	}
//
//	std::cout << std::endl;
//
//	return 0;
//}

//#include <list>
//int main()
//{
//	std::list<int> L{ 1,2,3,4 };
//
//	// Forward iteration
//	for (auto it = L.begin(); it != L.end(); ++it) 		{
//		std::cout << *it << '\t';
//	}
//	std::cout << std::endl;
//
//	// Backward iteration
//	for (auto it = L.end(); it != L.begin();) {
//		std::cout << *--it << '\t';
//	}
//}