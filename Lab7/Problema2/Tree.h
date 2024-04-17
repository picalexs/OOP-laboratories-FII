#pragma once
#include <stdio.h>

template <class T>
class Node
{
public:
	Node** childrenNodes;
	int childrenCount;
	int alocatedSpace;
	T data;
	Node() :childrenNodes(new Node* [10]), childrenCount(0), alocatedSpace(10) {}
};

template <class T>
class Tree
{
	Node<T>* root;
public:
	Tree() : root(nullptr) {}
	void add_node(T data, Node<T>* parentNode);
	Node<T>* get_node(int indexNode, Node<T>* parentNode);
	void delete_node(Node<T>* nodeToDelete);
	Node<T>* find(T value, Node<T>* parentNode, int(*callback)(T, T));
	void insert(int indexNode, T data, Node<T>* parentNode);
	void sort(Node<T>* parentNode, int(*callback)(T, T));
	int count(Node<T>* parentNode);
};


template <class T>
void updateAlocatedSize(Node<T>* parentNode)
{
	int newSize = parentNode->alocatedSpace * 2;
	Node<T>** tmp = new Node<T>*[newSize];
	for (int i = 0; i < parentNode->alocatedSpace; i++)
		tmp[i] = parentNode->childrenNodes[i];
	delete[] parentNode->childrenNodes;
	parentNode->childrenNodes = tmp;
	parentNode->alocatedSpace = newSize;
}


template <class T>
void Tree<T>::add_node(T data, Node<T>* parentNode)
{
	if (parentNode == nullptr)
	{
		this->root = new Node<T>;
		this->root->data = data;
		return;
	}
	if (parentNode->alocatedSpace <= parentNode->childrenCount)
		updateAlocatedSize(parentNode);

	parentNode->childrenNodes[parentNode->childrenCount] = new Node<T>;
	parentNode->childrenNodes[parentNode->childrenCount]->data = data;
	parentNode->childrenCount += 1;
}

template <class T>
Node<T>* Tree<T>::get_node(int indexNode, Node<T>* parentNode)
{
	if (indexNode < 0)
	{
		printf("Error: index can't be negative.");
		return nullptr;
	}
	if (parentNode == nullptr) {
		return this->root;
	}
	return parentNode->childrenNodes[indexNode];
}

template <class T>
void Tree<T>::delete_node(Node<T>* nodeToDelete)
{
	if (nodeToDelete == nullptr)
		return;

	for (int i = 0; i < nodeToDelete->childrenCount; i++)
	{
		if (nodeToDelete->childrenNodes[i])
			delete_node(nodeToDelete->childrenNodes[i]);
	}
	delete nodeToDelete;
}

template <class T>
Node<T>* Tree<T>::find(T value, Node<T>* parentNode, int(*callback)(T, T))
{
	if (parentNode == nullptr)
		return nullptr;
	if (callback(parentNode->data, value) == 0)
		return parentNode;
	for (int i = 0; i < parentNode->childrenCount; i++)
	{
		Node<T>* searchedNode = find(value, parentNode->childrenNodes[i], callback);
		if (searchedNode != nullptr)
			return searchedNode;
	}
	return nullptr;
}

template <class T>
void Tree<T>::insert(int indexNode, T data, Node<T>* parentNode)
{
	if (indexNode < 0)
	{
		printf("Error: index can't be negative.");
		return;
	}
	if (indexNode > parentNode->childrenCount)
		indexNode = parentNode->childrenCount;
	while (indexNode >= parentNode->alocatedSpace) {
		updateAlocatedSize(parentNode);
	}

	if (parentNode->childrenNodes[indexNode] == nullptr) {
		parentNode->childrenNodes[indexNode] = new Node<T>;
		parentNode->childrenNodes[indexNode]->data = data;
		parentNode->childrenCount += 1;
		return;
	}

	if (parentNode->childrenCount >= parentNode->alocatedSpace) {
		updateAlocatedSize(parentNode);
	}

	for (int i = parentNode->alocatedSpace; i > indexNode; --i)
	{
		parentNode->childrenNodes[i] = parentNode->childrenNodes[i - 1];
	}

	parentNode->childrenNodes[indexNode] = new Node<T>;
	parentNode->childrenNodes[indexNode]->data = data;
	parentNode->childrenCount += 1;
}

template <class T>
void Tree<T>::sort(Node<T>* parentNode, int(*callback)(T, T))
{
	for (int i = 0; i < parentNode->childrenCount - 1; i++) {
		for (int j = 0; j < parentNode->childrenCount; j++)
		{
			if ((callback != nullptr && callback(parentNode->childrenNodes[i]->data, parentNode->childrenNodes[j]->data))
				|| (callback == nullptr && parentNode->childrenNodes[i]->data > parentNode->childrenNodes[j]->data))
			{
				Node<T>* tmp = parentNode->childrenNodes[i];
				parentNode->childrenNodes[i] = parentNode->childrenNodes[j];
				parentNode->childrenNodes[j] = parentNode;
			}
		}
	}
}

template <class T>
int Tree<T>::count(Node<T>* parentNode)
{
	if (parentNode == nullptr)
		parentNode = this->root;
	int cnt = 0;
	for (int i = 0; i < parentNode->childrenCount; i++)
	{
		if (parentNode->childrenNodes[i] != nullptr)
			cnt += 1 + count(parentNode->childrenNodes[i]);
	}
	return cnt;
}



