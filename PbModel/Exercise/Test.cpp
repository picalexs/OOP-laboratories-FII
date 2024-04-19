#include "Test.h"
#include <iostream>
#include <varargs.h>
using namespace std;

std::ostream& operator<<(std::ostream& out, Test obj) {
	out << obj.getSum();
	return out;
}

void Test::Add(int nr, ...)
{
	va_list args;
	va_start(args, nr);
	for (int i = 0; i < nr; i++)
		sum += va_arg(args, int);
	va_end(args);
}

int Test::getSum() { return this->sum; }

Test& Test::operator++()
{
	cout << "postfix\n"; return (*this);
}

Test Test::operator++(int)
{
	cout << "sufix\n"; return (*this);
}

ostream& operator<<(ostream& out, Test& obj)
{
	out << obj.getSum();
	return out;
}