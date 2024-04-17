#include "Tree.h"
#include <iostream>
#include <cstring>

// Comparison function for sorting integers
int compareIntegers(int a, int b) {
	if (a < b) return -1;
	if (a > b) return 1;
	return 0;
}

// Comparison function for sorting floats
int compareFloats(float a, float b) {
	if (a < b) return -1;
	if (a > b) return 1;
	return 0;
}

// Comparison function for sorting strings
int compareStrings(const char* a, const char* b) {
	return strcmp(a, b);
}

int main() {
	// Test with integers
	Tree<int> intTree;
	intTree.add_node(5, nullptr);
	intTree.insert(0, 3, intTree.get_node(0, nullptr));
	intTree.insert(1, 7, intTree.get_node(0, nullptr));
	intTree.insert(0, 10, intTree.get_node(1, nullptr));
	intTree.insert(1, 7, intTree.get_node(1, nullptr));

	Node<int>* foundIntNode = intTree.find(7, nullptr, compareIntegers);
	if (foundIntNode != nullptr) {
		std::cout << "Node with value 7 found!\n";
	}
	else {
		std::cout << "Node with value 7 not found.\n";
	}

	int intNodeCount = intTree.count(nullptr);
	std::cout << "Number of nodes in the int tree: " << intNodeCount << std::endl;

	// Test with floats
	Tree<float> floatTree;
	floatTree.add_node(5.5f, nullptr);
	floatTree.insert(0, 3.3f, floatTree.get_node(0, nullptr));
	floatTree.insert(1, 7.7f, floatTree.get_node(0, nullptr));

	Node<float>* foundFloatNode = floatTree.find(7.7f, nullptr, compareFloats);
	if (foundFloatNode != nullptr) {
		std::cout << "Node with value 7.7 found!\n";
	}
	else {
		std::cout << "Node with value 7.7 not found.\n";
	}

	int floatNodeCount = floatTree.count(nullptr);
	std::cout << "Number of nodes in the float tree: " << floatNodeCount << std::endl;

	// Test with strings
	Tree<const char*> stringTree;
	stringTree.add_node("apple", nullptr);
	stringTree.insert(0, "banana", stringTree.get_node(0, nullptr));
	stringTree.insert(1, "orange", stringTree.get_node(0, nullptr));

	Node<const char*>* foundStringNode = stringTree.find("orange", nullptr, compareStrings);
	if (foundStringNode != nullptr) {
		std::cout << "Node with value 'orange' found!\n";
	}
	else {
		std::cout << "Node with value 'orange' not found.\n";
	}

	int stringNodeCount = stringTree.count(nullptr);
	std::cout << "Number of nodes in the string tree: " << stringNodeCount << std::endl;

	return 0;
}
