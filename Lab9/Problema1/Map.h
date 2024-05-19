#pragma once
using namespace std;

template <class K, class V>
class Node
{
public:
	K key;
	V value;
	int index;
	Node* next;
	Node(K k, V v, int i) : key(k), value(v), index(i), next(nullptr) {}
};

template <class K, class V>
class Map
{
private:
	Node<K, V>* root;
	int size;

	friend void DeleteNode();

public:
	Map();
	void Set(K key, V value);
	bool Get(const K& key, V& value);
	Node<K, V>* GetRoot();
	int Count();
	void Clear();
	bool Delete(const K& key);
	bool Includes(const Map<K, V>& map);

	V& operator[](const K& key);

	class Iterator
	{
		Node<K, V>* currentNode;
	public:
		Iterator(Node<K, V>* node) : currentNode(node) {}
		Node<K, V>* GetOtherNode() const { return currentNode; }
		bool operator!=(const Iterator& other) { return currentNode != other.GetOtherNode(); }
		void operator++() { currentNode = currentNode->next; }
		auto operator*() { return tie(currentNode->key, currentNode->value, currentNode->index); }
	};
	Iterator begin() { return Iterator(root); }
	Iterator end() { return Iterator(nullptr); }
};

template <class K, class V>
Map<K, V>::Map()
{
	this->root = nullptr;
	this->size = 0;
}

template <class K, class V>
void Map<K, V>::Set(K key, V value)
{
	if (root == nullptr) {
		root = new Node<K, V>(key, value, size);
		size++;
		return;
	}

	Node<K, V>* node = root;
	Node<K, V>* prev = nullptr;

	while (node != nullptr) {
		if (node->key == key) {
			node->value = value;
			return;
		}
		prev = node;
		node = node->next;
	}

	prev->next = new Node<K, V>(key, value, size);
	size++;
}



template <class K, class V>
bool Map<K, V>::Get(const K& key, V& value)
{
	Node<K, V>* node = this->root;
	while (node != nullptr)
	{
		if (node->key == key)
		{
			value = node->value;
			return true;
		}
		node = node->next;
	}
	return false;
}

template <class K, class V>
Node<K, V>* Map<K, V>::GetRoot()
{
	return this->root;
}

template <class K, class V>
int Map<K, V>::Count()
{
	return this->size;
}

template <class K, class V>
void DeleteNode(Node<K, V>* nodeToDelete)
{
	if (nodeToDelete == nullptr) return;
	DeleteNode(nodeToDelete->next);
	delete nodeToDelete;
}

template <class K, class V>
void Map<K, V>::Clear()
{
	DeleteNode(this->root);
	this->root = nullptr;
	this->size = 0;
}

template <class K, class V>
bool Map<K, V>::Delete(const K& key)
{
	if (this->size == 0) return false;
	if (this->root->key == key)
	{
		Node<K, V>* newRoot = this->root->next;
		delete this->root;
		this->root = newRoot;
		this->size -= 1;
		return true;
	}

	Node<K, V>* currentNode = this->root->next;
	Node<K, V>* previouseNode = this->root;
	while (currentNode != nullptr)
	{
		if (currentNode->key == key)
		{
			Node<K, V>* tmpNode = currentNode->next;
			delete currentNode;
			previouseNode->next = tmpNode;
			this->size -= 1;
			return true;
		}
		currentNode = currentNode->next;
	}

	return false;
}

template <class K, class V>
bool Map<K, V>::Includes(const Map<K, V>& map)
{
	Node<K, V> nodeOtherMap = map.GetRoot();
	while (nodeOtherMap != nullptr)
	{
		V tmpVal;
		if (Get(nodeOtherMap, tmpVal) == false)
			return false;
		nodeOtherMap = nodeOtherMap.next;
	}
	return true;
}
template <class K, class V>
V& Map<K, V>::operator[](const K& key)
{
	Node<K, V>* node = root;
	while (node != nullptr)
	{
		if (node->key == key)
		{
			return node->value;
		}
		node = node->next;
	}

	Set(key, V());
	node = root;
	while (node->next != nullptr)
	{
		node = node->next;
	}
	return node->value;
}
