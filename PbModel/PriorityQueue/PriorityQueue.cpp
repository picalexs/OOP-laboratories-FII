#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int size)
{
	this->vector = new int[size];
	this->count = 0;
	this->maxSize = size;
}

void sort(int* vector, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++)
		{
			if (vector[i] < vector[j])
			{
				int tmp = vector[i];
				vector[i] = vector[j];
				vector[j] = tmp;
			}
		}
	}
}

PriorityQueue& PriorityQueue::operator+=(int val)
{
	if (this->count + 1 <= maxSize)
	{
		this->vector[this->count++] = val;
		sort(this->vector, this->count);
		return *this;
	}
	sort(this->vector, this->count);
	this->vector[this->count] = val;
	sort(this->vector, this->count);
	return *this;
}

PriorityQueue::operator int()
{
	return this->count;
}

int PriorityQueue::operator--(int val)
{
	sort(this->vector, this->count);
	int nr = this->vector[0];
	this->vector -= 1;
	sort(this->vector, this->count);
	return nr;
}

int PriorityQueue::operator()(const char* string)
{
	if (string == nullptr)
		return 0;
	if (string[1] == 'u') {
		int sum = 0;
		for (int i = 0; i < this->count; i++)
			sum += this->vector[i];
		return sum;
	}
	if (string[1] == 'i') {
		int min = 10000000000;
		if (this->count != 0)
			min = this->vector[0];
		for (int i = 0; i < this->count; i++)
			if (this->vector[i] < min)
				min = this->vector[i];
		return min;
	}
	if (string[1] == 'a') {
		int max = 0;
		if (this->count != 0)
			max = this->vector[0];
		for (int i = 0; i < this->count; i++)
			if (this->vector[i] > max)
				max = this->vector[i];
		return max;
	}
}



