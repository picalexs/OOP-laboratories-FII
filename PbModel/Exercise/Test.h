#pragma once
#include <iostream>

class Test {
	int sum = 0;
public:
	void Add(int nr, ...);
	int getSum();
	Test& operator++();
	Test operator++(int);
	friend std::ostream& operator<<(std::ostream& out, Test obj);
};
