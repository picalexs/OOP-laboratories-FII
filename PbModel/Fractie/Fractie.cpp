#include "Fractie.h"
#include <iostream>

Fractie::Fractie(int n, int d)
{
	this->numerator = n;
	this->denumerator = d;
}

Fractie::Fractie(const Fractie& f)
{
	this->numerator = f.numerator;
	this->denumerator = f.denumerator;
}

Fractie::Fractie(const char* string)
{
	int idx = 0;
	int n = 0, d = 0;
	while (string[idx] != '/' && string[idx] != '\0')
	{
		n = n * 10 + string[idx] - '0';
		idx++;
	}
	if (string[idx] == '/') {
		idx++;
	}
	while (string[idx] != '/' && string[idx] != '\0')
	{
		d = d * 10 + string[idx] - '0';
		idx++;
	}

	if (d == 0) {
		d = 1;
	}
	this->numerator = n;
	this->denumerator = d;
}

int cmmdc(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

Fractie Fractie::operator+(const Fractie& f)
{
	Fractie sum = *this;
	int c = cmmdc(sum.denumerator, f.denumerator);
	sum.numerator = sum.numerator * f.denumerator + f.numerator * sum.denumerator;
	sum.denumerator *= f.denumerator;
	sum.numerator /= c;
	sum.denumerator /= c;
	return sum;
}

Fractie Fractie::operator*(const Fractie& f)
{
	Fractie mul = *this;
	mul.denumerator *= f.denumerator;
	mul.numerator *= f.numerator;
	return mul;
}

Fractie Fractie::operator-(const Fractie& f)
{
	Fractie sum = *this;
	int c = cmmdc(sum.denumerator, f.denumerator);
	sum.numerator = sum.numerator * f.denumerator - f.numerator * sum.denumerator;
	sum.denumerator *= f.denumerator;
	sum.numerator /= c;
	sum.denumerator /= c;
	return sum;
}

bool Fractie::operator==(const Fractie& f)
{
	Fractie f1 = *this, f2 = f;
	f1.numerator *= f2.denumerator;
	f2.numerator *= f1.denumerator;
	return (f1.numerator == f2.numerator);
}

int Fractie::operator[](const char* string)
{
	if (string[0] == 'n')
		return this->numerator;
	return this->denumerator;
}

void Fractie::print()
{
	std::cout << this->numerator << '/' << this->denumerator;
}

Fractie Fractie::simplify()
{
	int c = cmmdc(this->denumerator, this->numerator);
	this->denumerator /= c;
	this->numerator /= c;
	return *this;
}


