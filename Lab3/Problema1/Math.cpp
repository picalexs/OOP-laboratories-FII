#include "Math.h"
#include <cstdarg>
#include <cstring>

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

	int length = strlen(s1) + strlen(s2) + 1;
	char* result = new char[length];

	strcpy_s(result, length, s1);
	strcat_s(result, length, s2);

	return result;
}