#include <iostream>
#include "Array.h"
using namespace std;

int main() {
	try {
		Array<int> arr(10);
		arr += 5;
		arr += 3;
		arr += 7;
		arr += 1;
		arr.printArray();

		arr.Insert(2, 10);
		arr.printArray();

		Array<int> otherArr(20);
		otherArr += 20;
		otherArr += 30;
		otherArr += 40;
		arr.Insert(4, otherArr);
		arr.printArray();

		arr.Delete(3);
		arr.printArray();

		cout << "Trying to access element at index 15:" << endl;
		cout << arr[15] << endl;
	}
	catch (const std::exception& e) {
		cout << "Exception: " << e.what() << endl;
	}

	try {
		Array<int> arr(5);
		arr += 5;
		arr += 3;
		arr += 7;
		arr += 1;
		arr += 2;
		arr += 3; // Asta ar trebui sa dea exceptie pt. ca nu incape in lista
	}
	catch (const std::exception& e) {
		cout << "Exception: " << e.what() << endl;
	}

	try {
		Array<int> arr(5);
		arr += 5;
		arr += 3;
		arr += 7;
		arr += 1;
		arr.Sort();
	}
	catch (const std::exception& e) {
		cout << "Exception: " << e.what() << endl;
	}
	return 0;
}
