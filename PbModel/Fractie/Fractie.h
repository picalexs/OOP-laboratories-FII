#pragma once
#include <random>

class Fractie
{
	int numerator, denumerator;
public:
	Fractie(int n, int d);
	Fractie(const Fractie& f);
	Fractie(const char* string);
	Fractie operator+(const Fractie& f);
	Fractie operator*(const Fractie& f);
	Fractie operator-(const Fractie& f);
	bool operator==(const Fractie& f);
	int operator[](const char* string);
	void print();
	Fractie simplify();
};

