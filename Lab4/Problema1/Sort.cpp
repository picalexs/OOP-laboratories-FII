#include "Sort.h"

void swap(int& a, int& b)
{
	int aux = a;
	a = b;
	b = aux;
}

Sort::Sort(int inputCount, int minim, int maxim)
{
	if (inputCount < 0)
	{
		printf("Count ilegal!!\n");
		return;
	}
	srand(time(0));
	this->count = inputCount;
	this->vector = new int[inputCount];
	for (int i = 0; i < inputCount; i++)
		this->vector[i] = rand() % (maxim - minim + 1) + minim;
}

Sort::Sort() : vector(new int[10] {96, 43, 21, 35, 33, 12, 78, 54, 67, 89}), count(10) {}

Sort::Sort(int inputVector[], int inputCount)
{
	if (inputCount < 0 || inputVector == nullptr)
	{
		printf("Count ilegal!!\n");
		return;
	}
	this->vector = new int[inputCount];
	this->count = inputCount;
	for (int i = 0; i < inputCount; i++)
		this->vector[i] = inputVector[i];
}

Sort::Sort(int inputCount, ...)
{
	if (inputCount < 0)
	{
		printf("Count ilegal!!\n");
		return;
	}
	this->count = inputCount;
	this->vector = new int[count];

	va_list args;
	va_start(args, inputCount);
	for (int i = 0; i < count; i++)
		this->vector[i] = va_arg(args, int);
	va_end(args);
}

Sort::Sort(char* numbers)
{
	if (numbers == nullptr)
	{
		printf("Pointer is NULL!!\n");
		return;
	}
	this->count = 0;
	for (int i = 0; i < strlen(numbers); i++) {
		if (numbers[i] == ',')
			this->count++;
	}
	this->count++;
	this->vector = new int[this->count] {};

	int j = 0;
	for (int i = 0; i < strlen(numbers); i++)
	{
		if (numbers[i] == ',')
			j++;
		else
			this->vector[j] = this->vector[j] * 10 + (numbers[i] - '0');
	}
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 0; i < this->count; i++)
	{
		int key = this->vector[i];
		int j = i - 1;
		while (j >= 0 && (ascendent ? this->vector[j] > key : this->vector[j] < key))
		{
			this->vector[j + 1] = this->vector[j];
			j--;
		}
		this->vector[j + 1] = key;
	}
}

int Partition(int vector[], bool ascendent, int left, int right)
{
	int pivot = vector[left];
	int i = left;
	int j = right;

	while (i < j) {
		while (i < right && (ascendent ? vector[i] <= pivot : vector[i] >= pivot))
			i++;
		while (j > left && (ascendent ? vector[j] > pivot : vector[j] < pivot))
			j--;
		if (i < j)
			swap(vector[i], vector[j]);
	}

	swap(vector[left], vector[j]);
	return j;
}

void QuickSortRecursive(int vector[], bool ascendent, int left, int right)
{
	if (left >= right)
		return;
	int pivot = Partition(vector, ascendent, left, right);
	QuickSortRecursive(vector, ascendent, left, pivot - 1);
	QuickSortRecursive(vector, ascendent, pivot + 1, right);
}

void Sort::QuickSort(bool ascendent)
{
	QuickSortRecursive(this->vector, ascendent, 0, count - 1);
}

void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < this->count - 1; i++)
	{
		while (true)
		{
			bool swapped = false;
			for (int j = 0; j < this->count - i - 1; j++)
			{
				if (ascendent ? this->vector[j] > this->vector[j + 1] : this->vector[j] < this->vector[j + 1])
				{
					swap(this->vector[j], this->vector[j + 1]);
					swapped = true;
				}
			}
			if (!swapped)
				break;
		}
	}
}

void Sort::Print()
{
	for (int i = 0; i < this->count; i++)
		printf("%d ", this->vector[i]);
	printf("\n");
}

int Sort::GetElementsCount()
{
	return this->count;
}

int Sort::GetElementFromIndex(int index)
{
	if (index < 0 || index >= this->count)
	{
		printf("Index ilegal!!\n");
		return -1;
	}
	return this->vector[index];
}

