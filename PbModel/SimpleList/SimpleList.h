#include <iostream>
#include <initializer_list>
using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node* next;
};

template <class T>
class Iterator
{
protected:
	Node<T>* currentNode;
public:
	Iterator() : currentNode(nullptr) {}
	Iterator(Node<T>* node) : currentNode(node) {}
	T& operator*()
	{
		return currentNode->data;
	}
	Iterator& operator++()
	{
		currentNode = currentNode->next;
		return *this;
	}
	bool operator!=(const Iterator& other) const
	{
		return currentNode != other.currentNode;
	}
};

template <class T>
class SimpleList
{
	Node<T>* root;
	int nrElements = 0;

public:
	SimpleList(initializer_list<T> initList);
	SimpleList& operator+=(T val);
	SimpleList& operator+=(initializer_list<T> initList);
	SimpleList& operator-=(T val);
	int operator[](T val);
	operator int();

	Iterator<T> begin()
	{
		return Iterator<T>(root);
	}
	Iterator<T> end()
	{
		return Iterator<T>(nullptr);
	}
};

template <class T>
SimpleList<T>::SimpleList(initializer_list<T> initList)
{
	root = nullptr;
	for (const T& element : initList)
	{
		*this += element;
	}
}

template <class T>
SimpleList<T>& SimpleList<T>::operator+=(T val)
{
	Node<T>* newNode = new Node<T>;
	newNode->next = root;
	newNode->data = val;
	root = newNode;
	nrElements++;
	return *this;
}

template <class T>
SimpleList<T>& SimpleList<T>::operator+=(initializer_list<T> initList)
{
	for (const T& val : initList)
	{
		*this += val;
	}
	return *this;
}

template <class T>
SimpleList<T>& SimpleList<T>::operator-=(T val)
{
	Node<T>* current = root;
	Node<T>* previous = nullptr;
	while (current != nullptr)
	{
		if (current->data == val)
		{
			if (previous == nullptr)
			{
				root = current->next;
				delete current;
				current = root;
			}
			else
			{
				previous->next = current->next;
				delete current;
				current = previous->next;
			}
			nrElements--;
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
	return *this;
}

template <class T>
int SimpleList<T>::operator[](T val)
{
	int count = 0;
	Node<T>* current = root;
	while (current != nullptr)
	{
		if (current->data == val)
			count++;
		current = current->next;
	}
	return count;
}

template <class T>
SimpleList<T>::operator int()
{
	return nrElements;
}
