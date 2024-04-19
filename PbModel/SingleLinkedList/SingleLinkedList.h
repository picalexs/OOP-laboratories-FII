#pragma once

template <class T>
class Node
{
public:
	Node() : next(nullptr) {}
	T data;
	Node* next;
};

template<class T>
class SingleLinkedList
{
	Node<T>* root;
	Node<T>* currentNode;
public:
	SingleLinkedList();
	~SingleLinkedList();
	void deleteNode(Node<T>* parentNode);

	SingleLinkedList& operator+=(T val);

	bool operator&&(T val);
	bool searchNodeWithVal(Node<T>* parentNode, T val);

	operator bool();
	void print(void (*callback)(const T& val));
	void print(void (*callback)(T val));
	T pop_first();
};

template <class T>
SingleLinkedList<T>::SingleLinkedList()
{
	this->root = nullptr;
	this->currentNode = nullptr;
}

template <class T>
void SingleLinkedList<T>::deleteNode(Node<T>* parentNode)
{
	if (parentNode == nullptr)
		return;
	deleteNode(parentNode->next);
	delete parentNode;
}

template <class T>
SingleLinkedList<T>::~SingleLinkedList()
{
	deleteNode(this->root);
}

template <class T>
SingleLinkedList<T>& SingleLinkedList<T>::operator+=(T val)
{
	if (this->root == nullptr)
	{
		this->root = new Node<T>;
		this->currentNode = this->root;
		this->root->data = val;
		return *this;
	}

	this->currentNode->next = new Node<T>;
	this->currentNode = this->currentNode->next;
	this->currentNode->data = val;
	return *this;
}

template <class T>
bool SingleLinkedList<T>::searchNodeWithVal(Node<T>* parentNode, T val)
{
	if (parentNode->data == val) {
		return true;
	}
	if (parentNode->next != nullptr) {
		return searchNodeWithVal(parentNode->next, val);
	}
	return false;
}

template <class T>
bool SingleLinkedList<T>::operator&&(T val)
{
	return searchNodeWithVal(this->root, val);
}

template <class T>
SingleLinkedList<T>::operator bool()
{
	return this->root != nullptr;
}

template <class T>
void SingleLinkedList<T>::print(void (*callback)(const T& val))
{
	if (callback == nullptr)
		return;
	Node<T>* current = this->root;
	while (current != nullptr) {
		callback(current->data);
		current = current->next;
	}
}

template <class T>
void SingleLinkedList<T>::print(void(*callback)(T val))
{
	if (callback == nullptr)
		return;
	Node<T>* current = this->root;
	while (current != nullptr) {
		callback(current->data);
		current = current->next;
	}
}

template <class T>
T SingleLinkedList<T>::pop_first()
{
	Node<T>* first = this->root;
	this->root = this->root->next;
	T data = first->data;
	delete first;
	return data;
}
