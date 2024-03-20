#pragma once
#include <time.h>
#include <cstdarg>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
using namespace std;

class Sort
{
	int* vector;
	int count;
public:
	Sort(int inputCount, int minim, int maxim);
	Sort();
	Sort(int inputVector[], int inputCount);
	Sort(int inputCount, ...);
	Sort(char* numbers);

	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void Print();
	int  GetElementsCount();
	int  GetElementFromIndex(int index);
}
;

