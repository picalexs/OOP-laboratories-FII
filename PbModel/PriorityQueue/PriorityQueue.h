#pragma once

class PriorityQueue
{
	int* vector;
	int count;
	int maxSize;
public:
	PriorityQueue(int size);
	PriorityQueue& operator+=(int val);
	operator int();
	int operator--(int val);
	int operator()(const char* string);
};

