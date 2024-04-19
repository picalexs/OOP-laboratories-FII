#include <iostream>
#include "Test.h"
using namespace std;

int main()
{
	Test s;
	s.Add(5, 1, 2, 3, 4, 5);
	cout << s.getSum() << "\n";
	s++;
	++s;
	cout << s;
	return 0;
}