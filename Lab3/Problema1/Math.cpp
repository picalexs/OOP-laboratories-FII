#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <iostream>

using namespace std;

int Math::Add(int i1, int i2)
{
	return i1 + i2;
}

int Math::Add(int i1, int i2, int i3)
{
	return i1 + i2 + i3;
}

double Math::Add(double d1, double d2)
{
	return d1 + d2;
}

double Math::Add(double d1, double d2, double d3)
{
	return d1 + d2 + d3;
}

int Math::Mul(int i1, int i2)
{
	return i1 * i2;
}

int Math::Mul(int i1, int i2, int i3)
{
	return i1 * i2 * i3;
}

double Math::Mul(double d1, double d2)
{
	return d1 * d2;
}

double Math::Mul(double d1, double d2, double d3)
{
	return d1 * d2 * d3;
}

int Math::Add(int count, ...)
{
	int sum = 0;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
	{
		sum += va_arg(args, int);
	}
	va_end(args);
	return sum;
}

char* Math::Add(const char* s1, const char* s2)
{
	if (s1 == nullptr || s2 == nullptr)
		return nullptr;

	int lengthS1 = strlen(s1);
	int lengthS2 = strlen(s2);
	int maxLength = max(lengthS1, lengthS2) + 1;

	char* sum = new char[maxLength] {};
	for (int i = 0; i < abs(lengthS1 - lengthS2); i++)
	{
		strcat_s(sum, maxLength, "0");
	}
	if (lengthS1 < lengthS2) {
		strcat_s(sum, maxLength, s1);
	}
	else {
		strcat_s(sum, maxLength, s2);
	}

	int carry = 0;
	for (int i = maxLength - 2; i >= 0; --i)
	{
		int nr;
		if (lengthS1 < lengthS2) {
			nr = carry + sum[i] + s2[i] - 2 * '0';
		}
		else {
			nr = carry + s1[i] + sum[i] - 2 * '0';
		}

		carry = carry ? 0 : 1;
		if (nr > 9) {
			carry = 1;
		}
		sum[i + 1] = nr % 10 + '0';
	}

	sum[maxLength] = '\0';
	if (carry)
	{
		sum[0] = 1;
	}
	else
	{
		char* temp = new char[maxLength] {};
		strcpy_s(temp, maxLength, sum + 1);
		strcpy_s(sum, maxLength, temp);
	}
	return sum;
}