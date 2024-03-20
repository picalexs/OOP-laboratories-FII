#include <iostream>
#include "Sort.h"
using namespace std;

int main()
{
	int vectorTest[10] = { 8,2,5,1,3,9,0,4,7,6 };
	int count = 10;
	Sort list(vectorTest, count);
	list.InsertSort(true);
	list.Print();
	list.InsertSort();
	list.Print();

	Sort list2(10, 0, 7);
	list2.QuickSort(true);
	list2.Print();
	list2.QuickSort();
	list2.Print();

	Sort list3(11, 23, 45, 12, 34, 56, 78, 90, 94, 82, 37, 46);
	list3.InsertSort(true);
	list3.Print();
	list3.InsertSort();
	list3.Print();

	char numbers[] = "80,20,50,10,30,90,100,40,70,60";
	Sort list4(numbers);
	list4.InsertSort(true);
	list4.Print();


	Sort* list5 = new Sort();
	list5->BubbleSort(true);
	list5->Print();
	return 0;
}